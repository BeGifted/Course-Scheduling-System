#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QStyle>
#include <QDebug>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setStyle(QStyleFactory::create("Ubuntu"));


    // 这里使用代码来运行 MySQL 数据库
    QProcess process;
    process.start("C:/Program Files/mysql-8.0.27/bin/mysqld.exe");


    MainWindow w;
    w.show();

    return a.exec();
}
