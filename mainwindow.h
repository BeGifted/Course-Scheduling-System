#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QString>
#include <QFile>
#include <QList>
#include <QStandardItem>
#include <QTimer>
#include <QDateTime>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QButtonGroup>
#include <QMessageBox>
#include <QDebug>
#include <map>
#include <QPushButton>
#include <QVector>
#include <QException>
#include <cmath>
#include "classtask.h"
#include "classscheduletool.h"
#include "constantinfo.h"

const int MAXN = 1e2;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool classScheduling();

    QList<QMap<QString, QList<QString>>> coding(QList<ClassTask> classTaskList);

    QList<QString> codingTime(QList<QMap<QString, QList<QString>>> geneList);

    QMap<QString, QList<QString>> transformIndividual(QList<QString> resultGeneList);

    QMap<QString, QList<QString>> geneticEvolution(QMap<QString, QList<QString>> individualMap);
    QMap<QString, QList<QString>> hybridization(QMap<QString, QList<QString>> individualMap);
    QList<QString> selectiveGene(QList<QString> individualList);
    QList<QString> selectiveGene2(QList<QString> individualList, int firstTemp);
    QList<QString> closedGene(QMap<QString, QList<QString>> individualMap);
    QList<QString> geneticMutation(QList<QString> resultGeneList);
    QList<QString> conflictResolution(QList<QString> resultGeneList);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    QStandardItemModel * model;
    QSqlDatabase db;
    int couNum;
    int teaNum;
//   QMap<int, int> mT2C;//11
//   QVector<int> vC2T[MAXN];//1n
   QString teacher[MAXN];
   QString course[MAXN];
   //int course[MAXN][MAXN][MAXN];//班级+[][]
   ClassTask classTask;
   QList<ClassTask> classTaskList;
   QList<QString> classNoList;
   QMap<QString, QList<QString>> resultMap;
};

#endif // MAINWINDOW_H
