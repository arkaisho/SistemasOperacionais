#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);

private slots:
    void on_trem_1_slider_valueChanged(int value);

    void on_trem_2_slider_valueChanged(int value);

    void on_trem_3_slider_valueChanged(int value);

    void on_trem_4_slider_valueChanged(int value);

    void on_trem_5_slider_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
};

#endif
