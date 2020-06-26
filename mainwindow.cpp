#include "mainwindow.h"
#include <QDebug>
#include <QDir>
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileInfo>
#include<QFileInfoList>


#include <string>
#include    <QCryptographicHash>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->clear();
//     remove("g");
    QFile file("g");
    if(file.open(QIODevice::Truncate)){
        qDebug()<< "open success";
        ui->lineEdit->setText("open success");
        ui->lineEdit->show();
        QTextStream  ts(&file);
        ts << "HHHH";

     //   file.copy(close();
        file.close();

        file.open(QIODevice::Append);
        ui->textEdit->setText(file.readAll());
        ui->textEdit->show();

        QByteArray ba = "AAA";
        file.write(ba);

        file.close();


        file.open(QIODevice::Append);
        ui->textEdit->setText(file.readAll()  );
        file.close();

    }





}

MainWindow::~MainWindow()
{
    delete ui;
}
