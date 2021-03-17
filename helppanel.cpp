#include "helppanel.h"
#include "ui_helppanel.h"

HelpPanel::HelpPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpPanel)
{
    ui->setupUi(this);
}

HelpPanel::~HelpPanel()
{
    delete ui;
}
