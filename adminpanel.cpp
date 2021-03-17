#include "adminpanel.h"
#include "dialog.h"
#include "ui_adminpanel.h"
#include "ui_dialog.h"

#include <QFileDialog>

AdminPanel::AdminPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);

    ui->loginPanel->raise();
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

QString AdminPanel::getFileName()
{
    return this->ui->fileNameInput->text();
}

void AdminPanel::adminPasswordAuth()
{
    if (this->ui->adminPwdInput->text() == "password")
    {
        this->ui->loginPanel->hide();
    }
    else
    {
        this->ui->adminPwdInput->setText("");

        Dialog *prompt = new Dialog(nullptr, "The password was incorrect. Please try again!");

        prompt->setWindowTitle("Login Error");
        prompt->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        prompt->setAttribute(Qt::WA_DeleteOnClose);
        prompt->show();
    }
}


void AdminPanel::adminPasswordClear()
{
    this->ui->adminPwdInput->setText("");
}

void AdminPanel::loadFileName()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file..."), "", tr("TSV files (*.tsv)"));

    this->ui->fileNameInput->setText(fileName);

    emit newFileLoaded(fileName);

    this->~AdminPanel();
}
