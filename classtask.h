#ifndef CLASSTASK_H
#define CLASSTASK_H
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

class ClassTask
{
public :
    ClassTask();
      void setClassTask(int id, QString gradeNo, QString classNo, QString courseNo, QString teacherNo, QString courseAttr, int weeksNumber, QString isFix, QString classTime)
      {
          this->id = id;
          this->gradeNo = gradeNo;
          this->classNo = classNo;
          this->courseNo = courseNo;
          this->teacherNo = teacherNo;
          this->courseAttr = courseAttr;
          this->isFix = isFix;
          this->classTime = classTime;
          this->weeksNumber = weeksNumber;
      }
      int getId() {
         return id;
     }

       void setId(int id) {
         this ->id = id;
     }

       QString getGradeNo() {
         return gradeNo;
     }

       void setGradeNo(QString gradeNo) {
         this->gradeNo = gradeNo;
     }

       QString getClassNo() {
         return classNo;
     }

       void setClassNo(QString classNo) {
         this ->classNo = classNo;
     }

       QString getCourseNo() {
         return courseNo;
     }

       void setCourseNo(QString courseNo) {
         this ->courseNo = courseNo;
     }

       QString getTeacherNo() {
         return teacherNo;
     }

       void setTeacherNo(QString teacherNo) {
         this ->teacherNo = teacherNo;
     }

       QString getCourseAttr() {
         return courseAttr;
     }

       void setCourseAttr(QString courseAttr) {
         this ->courseAttr = courseAttr;
     }

       QString getIsFix() {
         return isFix;
     }

       void setIsFix(QString isFix) {
         this ->isFix = isFix;
     }

       QString getClassTime() {
         return classTime;
     }

     void setClassTime(QString classTime) {
         this ->classTime = classTime;
     }

     int getWeeksNumber() {
       return weeksNumber;
   }

   void setWeeksNumber(int weeksNumber) {
       this ->weeksNumber = weeksNumber;
   }

private:
    int id;
    int weeksNumber;
    QString gradeNo;
    QString classNo;
    QString courseNo;
    QString teacherNo;
    QString courseAttr;

     QString isFix;

     QString classTime;


};

#endif // CLASSTASK_H
