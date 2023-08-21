#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <qlabel.h>
#include <qstring.h>


int num = rand() % 101;
int chance=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_guessbutton_released()
{

    int gnum = ui->lineEdit->text().toInt();
    chance = chance+1;
    if(gnum == num)
    {
        QString message = "Congrats.. You Guessed it Right in " + QString::number(chance) + " chances";
        ui->hint->setText(message);
    }
    else if (gnum > num)
    {
        ui->hint->setText("Number is smaller than your Guessing");
    }
    else if (gnum < num)
    {
        ui->hint->setText("Number is larger than your Guessing");
    }

}


void MainWindow::on_startoverbutton_released()
{
    chance = 0;
    num = rand() % 101;
    ui->hint->setText("Game has been Started over");
    ui->lineEdit->setText("");
}

