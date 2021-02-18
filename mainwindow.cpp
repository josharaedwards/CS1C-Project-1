#include "mainwindow.h"
#include "contactsheet.h"
#include "ui_mainwindow.h"
#include "ui_contactsheet.h"

#include <QMessageBox>

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

void MainWindow::displayHelp()
{
    QMessageBox::information(this, "Navigating this pamphlet",
        "Using this pamplet is simple with just a few clicks!"
        "\n\n• The tabs on the side allow you to find the content that you need with ease."
        "\n\n• Using our sorting feature, you can see the football teams sorted by alphabetical order, NFL or AFL, stadiums capacity and more."
        "\n\n• If you have any trouble using the pamplet or simply want to contact us to request a new feature, please fill up the contact sheet!"
        "We would love to hear from you."
    );
}

void MainWindow::displayContact()
{
    ContactSheet *contact = new ContactSheet;

    contact->setAttribute(Qt::WA_DeleteOnClose);
    contact->show();
}
