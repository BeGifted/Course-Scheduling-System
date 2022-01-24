#ifndef CONSTANTINFO_H
#define CONSTANTINFO_H
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

class ConstantInfo
{
public:
    ConstantInfo();

    static QString IS_FIX;//是否固定 1不固定 2固定
    static QString UNFIXED_TIME;//未固定时间
    static QString IS_FIXED_TIME;//固定时间
    static QString CLASS_NO;//班级编号
    static QString TEACHER_NO;//教师编号
    static QString COURSE_NO;//课程编号
    static QString GRADE_NO;//年级编号
    static QString COURSE_ATTR;//课程属性
    static QString CLASS_TIME;//上课时间
    static QString CLASSROOM_NO;//教室编号
    static QString DEFAULT_CLASS_TIME;//默认课程编码
    static QString MAJOR_CODE;//主课码值（语、数、英）
    static QString MINOR_CODE;//副课码值（物、生）
    static QString PEANDSCIENCE_CODE;//体育课、科学课码值
    static QString MUSICANDART_CODE;//音乐课、美术课码值
    static int GENERATION;//遗传代数

};

#endif // CONSTANTINFO_H
