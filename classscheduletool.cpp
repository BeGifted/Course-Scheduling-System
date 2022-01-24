#include "classscheduletool.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

ClassScheduleTool::ClassScheduleTool()
{

}

//是否固定+年级编号+班级编号+教师编号+课程编号+课程属性+开课时间
//1             1              1              2             1              2             2
QString ClassScheduleTool::cutGene(QString aim, QString source) {
    if(aim == ConstantInfo::IS_FIX) return source.mid(0, 1);
    if(aim == ConstantInfo::GRADE_NO) return source.mid(1, 1);
    if(aim == ConstantInfo::CLASS_NO) return source.mid(2, 1);
    if(aim == ConstantInfo::TEACHER_NO) return source.mid(3, 2);
    if(aim == ConstantInfo::COURSE_NO) return source.mid(5, 1);
    if(aim == ConstantInfo::COURSE_ATTR) return source.mid(6, 2);
    if(aim == ConstantInfo::CLASS_TIME) return source.mid(8, 2);

    return "";
}


/**
 * @brief randomTime
 * @param gene
 * @param geneList
 * @return
 *
 * 随机生成时间片
 * 是否固定+年级编号+班级编号+教师编号+课程编号+课程属性+开课时间
 *
 */
QString ClassScheduleTool::randomTime(QString gene, QList<QString> geneList){
            //qDebug() << "fxxk";
    int Min = 1;
    int Max = 40;
    QString Time;
    //static QMap<QString, int> flag;
    //随机生成1到40范围的数字，并将其转化为字符串，方便进行编码
    int temp = Min + (rand() % (Max + 1 - Min));
    if (temp < 10)
        Time = "0" + QString::number(temp);
    else
        Time = "" + QString::number(temp);

    //qDebug() << flag.size();
    if (ClassScheduleTool::isTimeRepe(Time, gene, geneList)){
        //flag[Time] = 1;
        return Time;
    }
    else
        return randomTime(gene, geneList);
}

/**
 * @brief 判断同一个班是否在同一时间内上课有重复
 * @param time
 * @param gene
 * @param geneList
 * @return
 *
 * 是否固定+年级编号+班级编号+教师编号+课程编号+课程属性+开课时间
 */
bool ClassScheduleTool::isTimeRepe(QString time, QString gene, QList<QString> geneList){
    //获得班级编号
    QString classNo = cutGene(ConstantInfo::CLASS_NO, gene);
    //qDebug() << "班级编号" << classNo;
    for (QString str : geneList) {
        //判断班级编号是否相等
        if (classNo == cutGene(ConstantInfo::CLASS_NO, str)) {
            //班级编号相等的则判断时间是否有重复，没有返回true
            QString classTime = cutGene(ConstantInfo::CLASS_TIME, str);
            if (time == classTime) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief 计算适应度值
 * @param individualList
 * @return
 */
double ClassScheduleTool::calculateExpectedValue(QList<QString> individualList){
    double K1 = 0.3;//主课（语、数、英）所占权重
    double K2 = 0.1;//副课（物、生）所占权重
    double K3 = 0.1;//体育课、科学课所占权重
    double K4 = 0.1;//音乐课、美术课所占权重
    double K5 = 0.4;//课程离散程度所占权重
    int F1 = 0;//主课期望总值
    int F2 = 0;//副课期望总值
    int F3 = 0;//体育课、科学课期望总值
    int F4 = 0;//音乐课、美术课期望总值
    int F5;//课程离散程度期望总值
    double Fx;//适应度值

    for (QString gene : individualList) {
        QString courseAttr = ClassScheduleTool::cutGene(ConstantInfo::COURSE_ATTR, gene);//获得属性
        QString classTime = ClassScheduleTool::cutGene(ConstantInfo::CLASS_TIME, gene);//获得该课程的开课时间
        if (courseAttr == ConstantInfo::MAJOR_CODE) {
            F1 = F1 + ClassScheduleTool::calculateMajorExpect(classTime);
        } else if (courseAttr == ConstantInfo::MINOR_CODE) {
            F2 = F2 + ClassScheduleTool::calculateMinorExpect(classTime);
        } else if (courseAttr == ConstantInfo::PEANDSCIENCE_CODE) {
            F3 = F3 + ClassScheduleTool::calculatePeandscienceExpect(classTime);
        } else {
            F4 = F4 + ClassScheduleTool::calculateMusicandartExpect(classTime);
        }
    }
    F5 = ClassScheduleTool::calculateDiscreteExpect(individualList);
    Fx = K1 * F1 + K2 * F2 + K3 * F3 + K4 * F4 + K5 * F5;
    return Fx;
}

template<class T>
bool ClassScheduleTool::contain(T value[], T classTime, int size){
    for(int i = 0; i < size; i++){
        if(value[i] == classTime) return true;
    }
    return false;
}

/**
 * @brief 计算主课适应度
 * @param classTime
 * @return
01 09 17 25 33 主10
02 10 18 26 34 主8
03 11 19 27 35 主4
04 12 20 28 36 主2

05 13 21 29 37 主10
06 14 22 30 38 主8
07 15 23 31 39 主4
08 16 24 32 40 主0
 */
int ClassScheduleTool::calculateMajorExpect(QString classTime){
    QString tenExpectValue[] = {"01", "09", "17", "25", "33", "05", "13", "21", "29", "37"};//主课期望值为10时的时间片值
    QString eightExpectValue[] = {"02", "10", "18", "26", "34", "06", "14", "22", "30", "38"};//主课期望值为8时的时间片值
    QString fourExpectValue[] = {"03", "11", "19", "27", "35", "07", "15", "23", "31", "39"};//主课期望值为4时的时间片值
    QString twoExpectValue[] = {"04", "12", "20", "28", "36"};//主课期望值为2时的时间片值
    //QString zeroExpectValue[] = {"08","16","24","32","40"};//主课期望值为0时的时间片值

    if (contain(tenExpectValue, classTime, tenExpectValue->size())) {
        return 10;
    } else if (contain(eightExpectValue, classTime, eightExpectValue->size())) {
        return 8;
    } else if (contain(fourExpectValue, classTime, fourExpectValue->size())) {
        return 4;
    } else if (contain(twoExpectValue, classTime, twoExpectValue->size())) {
        return 2;
    } else {
        return 0;
    }
}

/**
 * @brief 计算副课适应度
 * @param classTime
 * @return
 *
01 09 17 25 33 副4
02 10 18 26 34 副10
03 11 19 27 35 副8
04 12 20 28 36 副2

05 13 21 29 37 副4
06 14 22 30 38 副10
07 15 23 31 39 副8
08 16 24 32 40 副0
 */
int ClassScheduleTool::calculateMinorExpect(QString classTime){
    QString tenExpectValue[] = {"02", "10", "18", "26", "34", "06", "14", "22", "30", "38"};//副课期望值为10时的时间片值
    QString eightExpectValue[] = {"03", "11", "19", "27", "35", "07", "15", "23", "31", "39"};//副课期望值为8时的时间片值
    QString fourExpectValue[] = {"01", "09", "17", "25", "33", "05", "13", "21", "29", "37"};//副课期望值为4时的时间片值
    QString twoExpectValue[] = {"04", "12", "20", "28", "36"};//副课期望值为2时的时间片值
    //QString zeroExpectValue[] = {"08","16","24","32","40"};//副课期望值为0时的时间片值

    if (contain(tenExpectValue, classTime, tenExpectValue->size())) {
        return 10;
    } else if (contain(eightExpectValue, classTime, eightExpectValue->size())) {
        return 8;
    } else if (contain(fourExpectValue, classTime, fourExpectValue->size())) {
        return 4;
    } else if (contain(twoExpectValue, classTime, twoExpectValue->size())) {
        return 2;
    } else {
        return 0;
    }
}

/**
 * @brief 计算体育课、科学课适应度
 * @param classTime
 * @return
 *
01 09 17 25 33 副0
02 10 18 26 34 副0
03 11 19 27 35 副0
04 12 20 28 36 副0

05 13 21 29 37 副2
06 14 22 30 38 副4
07 15 23 31 39 副8
08 16 24 32 40 副10
 */
int ClassScheduleTool::calculatePeandscienceExpect(QString classTime){
    QString tenExpectValue[] = {"08","16","24","32","40"};//期望值为10时的时间片值
    QString eightExpectValue[] = {"07", "15", "23", "31", "39"};//期望值为8时的时间片值
    QString fourExpectValue[] = {"06", "14", "22", "30", "38"};//期望值为4时的时间片值
    QString twoExpectValue[] = {"05", "13", "21", "29", "37"};//期望值为2时的时间片值
    //QString zeroExpectValue[] = {"01", "09", "17", "25", "33", "02", "10", "18", "26", "34", "03", "11", "19", "27", "35", "04", "12", "20", "28", "36"};//期望值为0时的时间片值

    if (contain(tenExpectValue, classTime, tenExpectValue->size())) {
        return 10;
    } else if (contain(eightExpectValue, classTime, eightExpectValue->size())) {
        return 8;
    } else if (contain(fourExpectValue, classTime, fourExpectValue->size())) {
        return 4;
    } else if (contain(twoExpectValue, classTime, twoExpectValue->size())) {
        return 2;
    } else {
        return 0;
    }
}

/**
 * @brief 计算音乐课、美术课适应度
 * @param classTime
 * @return
 *
01 09 17 25 33 副0
02 10 18 26 34 副0
03 11 19 27 35 副8
04 12 20 28 36 副10

05 13 21 29 37 副2
06 14 22 30 38 副4
07 15 23 31 39 副10
08 16 24 32 40 副8
 */
int ClassScheduleTool::calculateMusicandartExpect(QString classTime){
    QString tenExpectValue[] = {"04", "12", "20", "28", "36", "07", "15", "23", "31", "39"};//期望值为10时的时间片值
    QString eightExpectValue[] = {"03", "11", "19", "27", "35", "08","16","24","32","40"};//期望值为8时的时间片值
    QString fourExpectValue[] = {"06", "14", "22", "30", "38"};//期望值为4时的时间片值
    QString twoExpectValue[] = {"05", "13", "21", "29", "37"};//期望值为2时的时间片值
    //QString zeroExpectValue[] = {"01", "09", "17", "25", "33", "02", "10", "18", "26", "34"};//期望值为0时的时间片值

    if (contain(tenExpectValue, classTime, tenExpectValue->size())) {
        return 10;
    } else if (contain(eightExpectValue, classTime, eightExpectValue->size())) {
        return 8;
    } else if (contain(fourExpectValue, classTime, fourExpectValue->size())) {
        return 4;
    } else if (contain(twoExpectValue, classTime, twoExpectValue->size())) {
        return 2;
    } else {
        return 0;
    }
}

/**
 * @brief 计算课程离散程度期望值
 * @param individualList
 * @return
 */
int ClassScheduleTool::calculateDiscreteExpect(QList<QString> individualList){
    int F5 = 0;//离散程度期望值
    QMap<QString, QList<QString>> classTimeMap = courseGrouping(individualList);
    QMap<QString, QList<QString>>::iterator it = classTimeMap.begin();
    while (it != classTimeMap.end()) {
        QList<QString> classTimeList = it.value();
        if (classTimeList.size() > 1) {
            for (int i = 0; i < classTimeList.size() -1 ; i += 2) {
                int temp = classTimeList[i + 1].toInt() - classTimeList[i].toInt();
                F5 = F5 + judgingDiscreteValues(temp);
            }
        }
        it++;
    }
    return F5;
}

/**
 * @brief 将一个个体（班级课表）的同一门课程的所有上课时间进行一个统计，并且进行一个分组
 * @param individualList
 * @return
 */
QMap<QString, QList<QString>> ClassScheduleTool::courseGrouping(QList<QString> individualList) {
    QMap<QString, QList<QString>> classTimeMap;
    //先将一个班级课表所上的课程区分出来（排除掉重复的课程）
    for (QString gene : individualList) {
        classTimeMap[cutGene(ConstantInfo::COURSE_NO, gene)] = QList<QString>();
    }
    //遍历课程
    QMap<QString, QList<QString>>::iterator it = classTimeMap.begin();
    while (it != classTimeMap.end()) {
        QString courseNo = it.key();
        QList<QString> classTimeList;
        for (QString gene : individualList) {
            //获得同一门课程的所有上课时间片
            if (cutGene(ConstantInfo::COURSE_NO, gene) == courseNo) {
                classTimeList.append(cutGene(ConstantInfo::CLASS_TIME, gene));
            }
        }
        //将课程的时间片进行排序
        classTimeList.sort();
        classTimeMap[courseNo] = classTimeList;
        it++;
    }
    return classTimeMap;
}

/**
 * @brief 判断两课时间差在哪个区间并返回对应的期望值
 * @param temp
 * @return
 */
int ClassScheduleTool::judgingDiscreteValues(int temp) {
    int tenExpectValue[] = {5, 6, 7, 8, 9, 10, 11, 12, 13};//期望值为10时两课之间的时间差
    int sixExpectValue[] = {4, 14, 15, 16, 17, 18, 19, 20};//期望值为6时两课之间的时间差
    int fourExpectValue[] = {3, 21, 22, 23, 24, 25, 26, 27};//期望值为4时两课之间的时间差
    int twoExpectValue[] = {2, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38};//期望值为2时两课之间的时间差
    //int [] zeroExpectValue = {1,39};//期望值为0时两课之间的时间差
    if (contain(tenExpectValue, temp, 9)) {
        return 10;
    } else if (contain(sixExpectValue, temp, 8)) {
        return 6;
    } else if (contain(fourExpectValue, temp, 8)) {
        return 4;
    } else if (contain(twoExpectValue, temp, 12)) {
        return 2;
    } else {
        return 0;
    }
}
