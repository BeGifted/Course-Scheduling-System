#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(unsigned(time(nullptr)));
    this->model = new QStandardItemModel;

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("PK");
    db.setUserName("root");
    db.setPassword("root");
    bool ok = db.open();
    if (!ok){
        QMessageBox::information(this, "infor", "open failed");
        qDebug()<<"error open database because"<<db.lastError().text();
    }

    QSqlQuery query(db);
    query.exec("SET NAMES 'utf8'");
    query.exec("select * from teacher");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        teacher[id] = name;
    }

    query.exec("SET NAMES 'utf8'");
    query.exec("select * from course");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        course[id] = name;
    }

    //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("星期一"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("星期二"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("星期三"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("星期四"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("星期五"));

    this->ui->tableView->setModel(model);

    this->ui->tableView->setColumnWidth(0,150);
    this->ui->tableView->setColumnWidth(1,150);
    this->ui->tableView->setColumnWidth(2,150);
    this->ui->tableView->setColumnWidth(3,150);
    this->ui->tableView->setColumnWidth(4,150);

    this->ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignVCenter);
    this->ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
    this->ui->tableView->verticalHeader()->setDefaultSectionSize(40);

    /**
     * @brief 第一步获取class_task开课任务
     * @return
     * 'id'
     * 'gradeNo'
     * 'classNo'
     * 'courseNo'
     * 'teacherNo'
     * 'courseAttr'
     * 'weeksNumber'
     * 'isFix'
     * 'classTime'
     */
    query.exec("SET NAMES 'utf8'");
    query.exec("select * from class_task");
    QMap<QString, int> flag;
    while (query.next()) {
        QVariant temp;
        int id = query.value(0).toInt();
        QString gradeNo = query.value(1).toString();
        QString classNo = query.value(2).toString();
        QString courseNo = query.value(3).toString();
        QString teacherNo = query.value(4).toString();
        QString courseAttr = query.value(5).toString();
        int weeksNumber = query.value(6).toInt();
        QString isFix = query.value(7).toString();
        QString classTime = query.value(8).toString();
        classTask.setClassTask(id, gradeNo, classNo, courseNo, teacherNo, courseAttr, weeksNumber, isFix, classTime);
        classTaskList.append(classTask);
        if(!flag[classNo]) classNoList.append(classNo);
        flag[classNo] = 1;
        //qDebug() << classTask.getWeeksNumber();
    }
    qDebug() << "STEP 1 finished...";
    //qDebug() << classNoList.size();

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief 排课
 * @return
 */
bool MainWindow::classScheduling(){
    this->ui->progressBar->setValue(10);
    try {
        //第二步将开课任务进行编码
        QList<QMap<QString, QList<QString>>> geneList = coding(classTaskList);
        qDebug() << "STEP 2 finished...";
        this->ui->progressBar->setValue(20);
        //第三步开始进行时间分配（随机不重复）
        QList<QString> resultGeneList = codingTime(geneList);
        qDebug() << "STEP 3 finished...";
        this->ui->progressBar->setValue(30);
        //第四步对已分配好时间的基因进行分类，生成以班级为范围的个体
        QMap<QString, QList<QString>> individualMap = transformIndividual(resultGeneList);
        qDebug() << "STEP 4 finished...";
        this->ui->progressBar->setValue(40);
        //第五步进行遗传进化操作
        individualMap = geneticEvolution(individualMap);
        qDebug() << "STEP 5 finished...";
        this->ui->progressBar->setValue(100);
        resultMap = individualMap;
        //第六步分配教室...
        //第七步存入数据库...
        //第八步开课学期...
        //操作全部完成
        return true;
    } catch (QException e) {
        qDebug() << e.what();
        return false;
    }
}

/**
 * @brief 第二步将开课任务进行编码
 * @param classTaskList
 * @return
 *
 * 将从表中查询的开课任务对象集合进行编码，组成初始基因
 * 编码规则为：是否固定+年级编号+班级编号+教师编号+课程编号+课程属性+开课时间
 * 其中如果是否固定为否则开课时间默认填充为"00"
 *
 */
QList<QMap<QString, QList<QString>>> MainWindow::coding(QList<ClassTask> classTaskList){
    QList<QMap<QString, QList<QString>>> geneList;
    QMap<QString, QList<QString>> geneListMap;
    QList<QString> unFixedTimeGeneList;//不固定时间的编码基因组
    QList<QString> isFixedTimeGeneList;//固定时间的编码基因组
    for (ClassTask classTask : classTaskList) {
        //根据isFix的值判断是否固定，为1则不固定classTime默认填充”00“
        if (classTask.getIsFix() == "1") {
            //计算一周的上课次数，一次对应一个基因，2次对应两个基因。依此类推
            int size = classTask.getWeeksNumber();
            for (int i = 0; i < size; i++) {
                QString gene =
                    classTask.getIsFix() + classTask.getGradeNo() +
                    classTask.getClassNo() + classTask.getTeacherNo() +
                    classTask.getCourseNo() + classTask.getCourseAttr() +
                    ConstantInfo::DEFAULT_CLASS_TIME;
                unFixedTimeGeneList.append(gene);
            }
        }
        //isFix的值为2则classTime有值，需要对classTime的值进行切割
        if (classTask.getIsFix() == "2") {
            int size = classTask.getWeeksNumber();    //！一周的上课节数
            for (int i = 0; i < size; i++) {
                QString classTime = classTask.getClassTime().mid(i * 2, 2);
                QString gene =
                    classTask.getIsFix() + classTask.getGradeNo() +
                    classTask.getClassNo() + classTask.getTeacherNo() +
                    classTask.getCourseNo() + classTask.getCourseAttr() +
                    classTime;      //！固定的上课时间 第几节
                isFixedTimeGeneList.append(gene);
            }
        }
    }
    geneListMap[ConstantInfo::UNFIXED_TIME] = unFixedTimeGeneList;
    geneListMap[ConstantInfo::IS_FIXED_TIME] =  isFixedTimeGeneList;
    geneList.append(geneListMap);
    return geneList;
}

/**
 * @brief 第三步开始进行时间分配（随机不重复）
 * @param geneList
 * @return
 */
QList<QString> MainWindow::codingTime(QList<QMap<QString, QList<QString>>> geneList){
    QList<QString> resultGeneList;
    QList<QString> isFixedTimeGeneList = geneList[0][ConstantInfo::IS_FIXED_TIME];
    QList<QString> unFixedTimeGeneList = geneList[0][ConstantInfo::UNFIXED_TIME];
    //qDebug() << "总基因数"  << unFixedTimeGeneList.size();
    resultGeneList.append(isFixedTimeGeneList);//已经固定时间的编码时间已经排好，不需要再排
    //时间不固定的基因由程序进行随机分配
    //是否固定+年级编号+班级编号+教师编号+课程编号+课程属性+开课时间
    for (QString gene : unFixedTimeGeneList) {
        //！获取一个不重复的时间片值 "1 1 1 71 7 04 34"
        QString classTime = ClassScheduleTool::randomTime(gene, resultGeneList);
        gene = gene.mid(0, 8) + classTime;
        resultGeneList.append(gene);
        //qDebug() << gene;
    }
    return resultGeneList;
}

/**
 * @brief 第四步对已分配好时间的基因进行分类，生成以班级为范围的个体
 * @param resultGeneList
 * @return
 *
 * 将编码按班级进行分类，形成初始个体
 */
QMap<QString, QList<QString>> MainWindow::transformIndividual(QList<QString> resultGeneList){
    QMap<QString, QList<QString>> individualMap;
    //！所有课程任务的班级列表QList<QString> classNoList
    for (QString classNo : classNoList) {
        QList<QString> geneList;
        for (QString gene : resultGeneList) {
            if (classNo == ClassScheduleTool::cutGene(ConstantInfo::CLASS_NO, gene)) {
                geneList.append(gene);
            }
        }
        if (geneList.size() > 1) {
            individualMap[classNo] = geneList;
        }
    }
    return individualMap;
}


/**
 * @brief 第五步进行遗传进化操作
 * @param individualMap
 * @return
 */
QMap<QString, QList<QString>> MainWindow::geneticEvolution(QMap<QString, QList<QString>> individualMap){
    int generation = ConstantInfo::GENERATION; //100
    QList<QString> resultGeneList;
    for (int i = 0; i < generation; ++i) {
        //第一步完成交叉操作，产生新一代的父本，以及适应度计算
        individualMap = hybridization(individualMap);
        //第二步合拢个体准备变异
        resultGeneList = closedGene(individualMap);
        //第三步开始变异
        //resultGeneList = geneticMutation(resultGeneList);
        //第四步进行冲突检测并消除
        conflictResolution(resultGeneList);
        //第五步将冲突消除后的个体再次进行分割，按班级进行分配准备进入下一次的进化
        individualMap = transformIndividual(conflictResolution(resultGeneList));
        if(i == generation / 4) this->ui->progressBar->setValue(50);
        if(i == generation / 2) this->ui->progressBar->setValue(70);
        if(i == generation / 4 * 3) this->ui->progressBar->setValue(80);
    }
    return individualMap;
}

/**
 * @brief 5.1 完成交叉操作，产生新一代的父本
 * @param individualMap
 * @return
 */
QMap<QString, QList<QString>> MainWindow::hybridization(QMap<QString, QList<QString>> individualMap){
    QMap<QString, QList<QString>>::iterator iter = individualMap.begin();
    double sum = 0;
    static int times = 0;
    while (iter != individualMap.end()) {
        QString classNo = iter.key();
        QList<QString> individualList = iter.value();
        QList<QString> oldIndividualList = individualList;
        //进行基因的交叉操作生成新个体
        individualList = selectiveGene(individualList);
        //对父代的适应度值和新生成的子代适应值进行对比，选择适应度值高的一个进入下一代的遗传
        double NEW = ClassScheduleTool::calculateExpectedValue(individualList);
        double OLD = ClassScheduleTool::calculateExpectedValue(oldIndividualList);
        if (NEW >= OLD) {
            individualMap[classNo] = individualList;
            sum += NEW;
        } else {
            individualMap[classNo] = oldIndividualList;
            sum += OLD;
        }
        iter++;
    }
    qDebug() << "第" << ++times << "次适应度：" << sum;
    return individualMap;
}

//个体间的随机选择两条基因准备进行杂交并生成一个新个体
QList<QString> MainWindow::selectiveGene(QList<QString> individualList){
    int min = 0;
    int max = individualList.size() - 1;
    bool flag;
    do {
        //随机生成0到individualList.size - 1的两个数，用来选取基因
        int firstTemp = min + (rand() % (max + 1 - min));//选取第一个随机数
        int secondTemp = min + (rand() % (max + 1 - min));//选取第二个随机数
        QString firstGene = individualList[firstTemp];//获取第一条基因
        QString secondGene = individualList[secondTemp];//获取第二条基因
        //判断选择的两个随机数是否相同，确保不会选择同一条基因进行交叉操作
        if (firstTemp == secondTemp) {
            flag = false;
        } else if (ClassScheduleTool::cutGene(ConstantInfo::IS_FIX, firstGene) == "2" ||
                      ClassScheduleTool::cutGene(ConstantInfo::IS_FIX, secondGene) == "2") {
            //判断选择的两条基因对应的时间值是否固定，如果固定则重新选择两条
            flag = false;
        } else {
            //分别获取所选的两条基因的时间片值
            QString firstClassTime = ClassScheduleTool::cutGene(ConstantInfo::CLASS_TIME, firstGene);
            QString secondClassTime = ClassScheduleTool::cutGene(ConstantInfo::CLASS_TIME, secondGene);
            //将它们的时间进行交换
            firstGene = firstGene.mid(0, 8) + secondClassTime;
            secondGene = secondGene.mid(0, 8) + firstClassTime;
            //对原有的基因进行移除，然后将交换过时间的两条基因添加进去
            individualList[firstTemp] = firstGene;
            individualList[secondTemp] = secondGene;
            flag = true;
        }
    } while (!flag);
    return individualList;
}


/**
 * @brief 5.2 将分割好的个体（按班级分好的课表）重新合拢在一起，方便进行冲突检测
 * @param individualMap
 * @return
 */
QList<QString> MainWindow::closedGene(QMap<QString, QList<QString>> individualMap) {
    QList<QString> resultGeneList;
    QMap<QString, QList<QString>>::iterator it = individualMap.begin();
    while (it != individualMap.end()) {
        resultGeneList.append(it.value());
        it++;
    }
    return resultGeneList;
}

/**
 * @brief 5.3 基因变异操作
 * @param resultGeneList
 * @return
 */
QList<QString> MainWindow::geneticMutation(QList<QString> resultGeneList) {
    int min = 0;
    int max = resultGeneList.size() - 1;
    double mutationRate = 0.01;//变异概率
    int mutationNumber = ceil(mutationRate * resultGeneList.size());//每一代所要选取的变异个数,计算公式为基因数量*变异率
    if (mutationNumber < 1) {
        mutationNumber = 1;
    }
    for (int i = 0; i < mutationNumber; ) {
        int temp = min + (rand() % (max + 1 - min));//生成随机数
        //qDebug() << temp;
        QString gene = resultGeneList[temp];
        if (ClassScheduleTool::cutGene(ConstantInfo::IS_FIX, gene) == "2") {
            break;
        } else {
            QString newClassTime = ClassScheduleTool::randomTime(gene, resultGeneList);
            qDebug() << newClassTime;
            qDebug() << resultGeneList;
            gene = gene.mid(0, 8) + newClassTime;
            resultGeneList[temp] = gene;
            i++;
                    qDebug() << "fxxk";
        }
    }
            qDebug() << "fxxk";
    return resultGeneList;
}

/**
 * @brief 5.4 解决冲突，同一时间一个教师上多门课的冲突
 * @param resultGeneList
 * @return
 */
QList<QString> MainWindow::conflictResolution(QList<QString> resultGeneList) {
    exit:
    for (int i = 0; i < resultGeneList.size(); ++i) {
        QString gene = resultGeneList[i];
        QString teacherNo = ClassScheduleTool::cutGene(ConstantInfo::TEACHER_NO, gene);
        QString classTime = ClassScheduleTool::cutGene(ConstantInfo::CLASS_TIME, gene);
        for (int j = i + 1; j < resultGeneList.size(); ++j) {
            QString tempGene = resultGeneList[j];
            QString tempTeacherNo = ClassScheduleTool::cutGene(ConstantInfo::TEACHER_NO, tempGene);
            QString tempClassTime = ClassScheduleTool::cutGene(ConstantInfo::CLASS_TIME, tempGene);
            if (teacherNo == tempTeacherNo && classTime == tempClassTime) {
                QString firstGene = resultGeneList[i];//获取第一条基因
                QString secondGene = resultGeneList[j];//获取第二条基因
                if (ClassScheduleTool::cutGene(ConstantInfo::IS_FIX, firstGene) == "2" &&
                              ClassScheduleTool::cutGene(ConstantInfo::IS_FIX, secondGene) == "2") {
                    qDebug() << "互斥条件设置错误！";
                    QMessageBox::information(this, "infor", "互斥条件设置错误！");
                    return resultGeneList;
                }
                if (ClassScheduleTool::cutGene(ConstantInfo::IS_FIX, firstGene) == "2") {
                    resultGeneList = selectiveGene2(resultGeneList, j);
                }else if(ClassScheduleTool::cutGene(ConstantInfo::IS_FIX, secondGene) == "2") {
                    resultGeneList = selectiveGene2(resultGeneList, i);
                }else{
                    resultGeneList = selectiveGene2(resultGeneList, j);
                }

//                QString newClassTime = ClassScheduleTool::randomTime(gene, resultGeneList);
//                gene = gene.mid(0, 8) + newClassTime;
                goto exit;
            }
        }
    }
    return resultGeneList;
}

QList<QString> MainWindow::selectiveGene2(QList<QString> individualList, int firstTemp){
    bool flag;
    int min = 0;
    int max = individualList.size() - 1;
    int secondTemp = min + (rand() % (max + 1 - min));

    do {
        QString firstGene = individualList[firstTemp];//获取第一条基因
        QString secondGene = individualList[secondTemp];//获取第二条基因
        if (ClassScheduleTool::cutGene(ConstantInfo::IS_FIX, secondGene) == "2" ||
                ClassScheduleTool::cutGene(ConstantInfo::CLASS_NO, secondGene) != ClassScheduleTool::cutGene(ConstantInfo::CLASS_NO, firstGene)) {
            secondTemp = min + (rand() % (max + 1 - min));
            flag = false;
        } else {
            //分别获取所选的两条基因的时间片值
            QString firstClassTime = ClassScheduleTool::cutGene(ConstantInfo::CLASS_TIME, firstGene);
            QString secondClassTime = ClassScheduleTool::cutGene(ConstantInfo::CLASS_TIME, secondGene);
            //将它们的时间进行交换
            firstGene = firstGene.mid(0, 8) + secondClassTime;
            secondGene = secondGene.mid(0, 8) + firstClassTime;
            //对原有的基因进行移除，然后将交换过时间的两条基因添加进去
            individualList[firstTemp] = firstGene;
            individualList[secondTemp] = secondGene;
            flag = true;
        }
    } while (!flag);
    return individualList;
}

/**
 * @brief 开始排课
 */
void MainWindow::on_pushButton_clicked()
{
//    QString plan[11][11];
//    exit:
        classScheduling();
//        QMap<QString, QList<QString>>::iterator it = resultMap.begin();
//        while(it != resultMap.end()){
//            QList<QString> tempList = it.value();
//            for(QString gene : tempList){
//                QString classTime = ClassScheduleTool::cutGene(ConstantInfo::CLASS_TIME, gene);
//                QString courseNo = ClassScheduleTool::cutGene(ConstantInfo::COURSE_NO, gene);
//                int Time = classTime.toInt();
//                plan[(Time - 1) % 8][(Time - 1) / 8] =  courseNo;
//            }
//            for(int i = 0; i < 5; i++){
//                int num = 0;
//                for(int j = 0; j < 8; j++){
//                     if(plan[j][i] == "1") //语文
//                         num++;
//                }
//                if(num > 2) goto exit;
//            }
//            it++;
//        }
}

/**
 * @brief 按班级查询
 * 是否固定+年级编号+班级编号+教师编号+课程编号+课程属性+开课时间
 */
void MainWindow::on_pushButton_2_clicked()
{
    this->model = new QStandardItemModel;
    //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("星期一"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("星期二"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("星期三"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("星期四"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("星期五"));
    this->ui->tableView->setModel(model);
    this->ui->tableView->setColumnWidth(0,150);
    this->ui->tableView->setColumnWidth(1,150);
    this->ui->tableView->setColumnWidth(2,150);
    this->ui->tableView->setColumnWidth(3,150);
    this->ui->tableView->setColumnWidth(4,150);
    this->ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignVCenter);
    this->ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
    this->ui->tableView->verticalHeader()->setDefaultSectionSize(40);

    int temp = this->ui->comboBox->currentIndex();
    QString id = QString::number(temp);
    QList<QString> resultList = resultMap[id];
    for(QString gene : resultList){
        QString classTime = ClassScheduleTool::cutGene(ConstantInfo::CLASS_TIME, gene);
        QString teacherNo = ClassScheduleTool::cutGene(ConstantInfo::TEACHER_NO, gene);
        QString courseNo = ClassScheduleTool::cutGene(ConstantInfo::COURSE_NO, gene);

        int Time = classTime.toInt();

        QVariant temp = course[courseNo.toInt()] + "  +  " + teacher[teacherNo.toInt()];
        //qDebug() << teacherNo.toInt() << " " << teacher[teacherNo.toInt()];
        QStandardItem* item = new QStandardItem();
        item->setData(temp, Qt::EditRole);
        this->model->setItem((Time - 1) % 8, (Time - 1) / 8, item);
    }

}
