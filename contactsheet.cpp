#include "contactsheet.h"
#include "ui_contactsheet.h"

#include <QMessageBox>

ContactSheet::ContactSheet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactSheet)
{
    ui->setupUi(this);
}

ContactSheet::~ContactSheet()
{
    delete ui;
}

void ContactSheet::sendBtnHandler()
{
    QMessageBox msgBox;

    msgBox.setStyleSheet("QMessageBox { font: 75 10pt \"Consolas\"; background-color: rgb(236, 239, 244); color: rgb(46, 52, 64); }");
    msgBox.setWindowTitle("Success");
    msgBox.setText("Message sent successfully!");

    msgBox.exec();
}

void ContactSheet::clear()
{
    ui->plainTextEdit->setPlainText("");
}
