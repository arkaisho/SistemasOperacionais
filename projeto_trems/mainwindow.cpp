#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem1 = new Trem(1,10,70);
    trem2 = new Trem(2,190,10);
    trem3 = new Trem(3,370,70);
    trem4 = new Trem(4,130,250);
    trem5 = new Trem(5,250,250);

    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1:
        ui->trem_1->setGeometry(x,y,25,25);
        ui->t1_coordinates->setText("X="+QString::number(x)+", Y="+QString::number(y));
        break;
    case 2:
        ui->trem_2->setGeometry(x,y,25,25);
        ui->t2_coordinates->setText("X="+QString::number(x)+", Y="+QString::number(y));
        break;
    case 3:
        ui->trem_3->setGeometry(x,y,25,25);
        ui->t3_coordinates->setText("X="+QString::number(x)+", Y="+QString::number(y));
        break;
    case 4:
        ui->trem_4->setGeometry(x,y,25,25);
        ui->t4_coordinates->setText("X="+QString::number(x)+", Y="+QString::number(y));
        break;
    case 5:
        ui->trem_5->setGeometry(x,y,25,25);
        ui->t5_coordinates->setText("X="+QString::number(x)+", Y="+QString::number(y));
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_trem_1_slider_valueChanged(int value)
{
    trem1->setVelocidade(value);
    if (value!=0) {
        ui->velocidade_trem_1->setText(QString::number(value));
    }else{
        ui->velocidade_trem_1->setText("0");
    }
}

void MainWindow::on_trem_2_slider_valueChanged(int value)
{
    trem2->setVelocidade(value);
    if (value!=0) {
        ui->velocidade_trem_2->setText(QString::number(value));
    }else{
        ui->velocidade_trem_2->setText("0");
    }
}

void MainWindow::on_trem_3_slider_valueChanged(int value)
{
    trem3->setVelocidade(value);
    if (value!=0) {
        ui->velocidade_trem_3->setText(QString::number(value));
    }else{
        ui->velocidade_trem_3->setText("0");
    }
}

void MainWindow::on_trem_4_slider_valueChanged(int value)
{
    trem4->setVelocidade(value);
    if (value!=0) {
        ui->velocidade_trem_4->setText(QString::number(value));
    }else{
        ui->velocidade_trem_4->setText("0");
    }
}

void MainWindow::on_trem_5_slider_valueChanged(int value)
{
    trem5->setVelocidade(value);
    if (value!=0) {
        ui->velocidade_trem_5->setText(QString::number(value));
    }else{
        ui->velocidade_trem_5->setText("0");
    }
}
