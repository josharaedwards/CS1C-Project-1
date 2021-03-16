#include "contactsheet.h"
#include "ui_contactsheet.h"

#include <QMessageBox>

///Contact sheet GUI allows the user to send inquiries and questions.
///The window prompt the user to fill in boxes such as full name, e-mail and message. When the message is sent a pop up window let
///the user know that was suscesfully sent
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
