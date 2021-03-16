#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::Dialog(QWidget *parent, QString dialogText) :
    QWidget(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->dialogText->setText(dialogText);
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::closeDialog()
{
    this->~Dialog();
}
