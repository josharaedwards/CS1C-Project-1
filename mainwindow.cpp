#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->displayHome();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAdmin()
{
    this->ui->adminBtn->setStyleSheet("border:none;font: 75 12pt \"Consolas\";background-color: rgb(236, 239, 244);color: rgb(46, 52, 64);");
    this->ui->homeBtn->setStyleSheet("border:none;font: 75 12pt \"Consolas\";background-color: rgb(46, 52, 64);color: rgb(236, 239, 244);");
    this->ui->sortBtn->setStyleSheet("border:none;font: 75 12pt \"Consolas\";background-color: rgb(46, 52, 64);color: rgb(236, 239, 244);");
    this->ui->adminContent->raise();
}

void MainWindow::displayHome()
{
    this->ui->adminBtn->setStyleSheet("border:none;font: 75 12pt \"Consolas\";background-color: rgb(46, 52, 64);color: rgb(236, 239, 244);");
    this->ui->homeBtn->setStyleSheet("border:none;font: 75 12pt \"Consolas\";background-color: rgb(236, 239, 244);color: rgb(46, 52, 64);");
    this->ui->sortBtn->setStyleSheet("border:none;font: 75 12pt \"Consolas\";background-color: rgb(46, 52, 64);color: rgb(236, 239, 244);");
    this->ui->homeContent->raise();
}

void MainWindow::displaySort()
{
    this->ui->adminBtn->setStyleSheet("border:none;font: 75 12pt \"Consolas\";background-color: rgb(46, 52, 64);color: rgb(236, 239, 244);");
    this->ui->homeBtn->setStyleSheet("border:none;font: 75 12pt \"Consolas\";background-color: rgb(46, 52, 64);color: rgb(236, 239, 244);");
    this->ui->sortBtn->setStyleSheet("border:none;font: 75 12pt \"Consolas\";background-color: rgb(236, 239, 244);color: rgb(46, 52, 64);");
    this->ui->sortContent->raise();
}
