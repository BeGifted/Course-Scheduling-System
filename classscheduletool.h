#ifndef CLASSSCHEDULETOOL_H
#define CLASSSCHEDULETOOL_H
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
#include <QMap>
#include <QPushButton>
#include <QVector>
#include <algorithm>
#include "constantinfo.h"

class ClassScheduleTool
{
public:
    ClassScheduleTool();
    static QString randomTime(QString gene, QList<QString> geneList);
    static bool isTimeRepe(QString time, QString gene, QList<QString> geneList);
    static QString cutGene(QString aim, QString source);
    static double calculateExpectedValue(QList<QString> individualList);
    static int calculateMajorExpect(QString classTime);
    static int calculateMinorExpect(QString classTime);
    static int calculatePeandscienceExpect(QString classTime);
    static int calculateMusicandartExpect(QString classTime);
    static int calculateDiscreteExpect(QList<QString> individualList);
    template<class T>
    static bool contain(T value[], T classTime, int size);
    static QMap<QString, QList<QString>> courseGrouping(QList<QString> individualList);
    static int judgingDiscreteValues(int temp);
};

#endif // CLASSSCHEDULETOOL_H
