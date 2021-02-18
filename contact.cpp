#include "contact.h"
#include "ui_contact.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

contact::contact(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::contact)
{
    ui->setupUi(this);
    QPushButton * clear = new QPushButton(this);
    connect(clear,SIGNAL(clicked()), this, SLOT(clear()));
}

contact::~contact()
{
    delete ui;
}


void contact::on_pushButton_clicked()
{
    QMessageBox::information(this, "send message","Message sent suscefully!");

}

void contact::clear()
{
    ui->plainTextEdit->setPlainText("");
}
