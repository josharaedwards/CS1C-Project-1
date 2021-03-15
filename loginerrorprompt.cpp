#include "loginerrorprompt.h"
#include "ui_loginerrorprompt.h"

LoginErrorPrompt::LoginErrorPrompt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginErrorPrompt)
{
    ui->setupUi(this);
}

LoginErrorPrompt::~LoginErrorPrompt()
{
    delete ui;
}

void LoginErrorPrompt::closeLoginErrorPrompt()
{
    this->~LoginErrorPrompt();
}
