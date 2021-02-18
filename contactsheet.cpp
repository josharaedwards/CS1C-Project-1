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
    QMessageBox::information(this, "Contact","Message sent successfully!");
}

void ContactSheet::clear()
{
    ui->plainTextEdit->setPlainText("");
}
