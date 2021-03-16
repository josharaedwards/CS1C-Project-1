#include "mainwindow.h"
#include "contactsheet.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "ui_contactsheet.h"
#include "ui_dialog.h"
#include "init.h"

#include <QMessageBox>

//Global Football Teams Data Holders
QVector<Football> footballTeams;
QVector<Football> teamsNFL;
QVector<Football> teamsAFC;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->displayHome();
    ui->loginPanel->raise();

    footballTeams =  fileRead("C:/Users/josha/Documents/GitHub/CS1C-Project-1/NFL Information.tsv");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAdmin()
{
    this->ui->adminBtn->setStyleSheet("border:none; font: 75 12pt \"Consolas\"; background-color: rgb(236, 239, 244); color: rgb(46, 52, 64);");
    this->ui->homeBtn->setStyleSheet("border:none; font: 75 12pt \"Consolas\"; background-color: rgb(46, 52, 64); color: rgb(236, 239, 244);");
    this->ui->sortBtn->setStyleSheet("border:none; font: 75 12pt \"Consolas\"; background-color: rgb(46, 52, 64); color: rgb(236, 239, 244);");
    this->ui->adminContent->raise();
}

void MainWindow::displayHome()
{
    this->ui->adminBtn->setStyleSheet("border:none; font: 75 12pt \"Consolas\"; background-color: rgb(46, 52, 64); color: rgb(236, 239, 244);");
    this->ui->homeBtn->setStyleSheet("border:none; font: 75 12pt \"Consolas\"; background-color: rgb(236, 239, 244); color: rgb(46, 52, 64);");
    this->ui->sortBtn->setStyleSheet("border:none; font: 75 12pt \"Consolas\"; background-color: rgb(46, 52, 64); color: rgb(236, 239, 244);");
    this->ui->homeContent->raise();
}

void MainWindow::displaySort()
{
    int numOfEntries = footballTeams.size();
    this->ui->tableWidget->setRowCount(numOfEntries);

    populateSortCells();

    this->ui->adminBtn->setStyleSheet("border:none; font: 75 12pt \"Consolas\"; background-color: rgb(46, 52, 64); color: rgb(236, 239, 244);");
    this->ui->homeBtn->setStyleSheet("border:none; font: 75 12pt \"Consolas\"; background-color: rgb(46, 52, 64); color: rgb(236, 239, 244);");
    this->ui->sortBtn->setStyleSheet("border:none; font: 75 12pt \"Consolas\"; background-color: rgb(236, 239, 244); color: rgb(46, 52, 64);");
    this->ui->sortContent->raise();
}

void MainWindow::displayHelp()
{
    QMessageBox msgBox;

    msgBox.setStyleSheet("QMessageBox { font: 75 10pt \"Consolas\"; background-color: rgb(236, 239, 244); color: rgb(46, 52, 64); }");
    msgBox.setWindowTitle("Navigating this pamplet");
    msgBox.setText(
        "Using this pamplet is simple with just a few clicks!"
        "\n\n• The tabs on the side allow you to find the content that you need with ease."
        "\n\n• Using our sorting feature, you can see the football teams sorted by alphabetical order, NFL or AFL, stadiums capacity and more."
        "\n\n• If you have any trouble using the pamphlet or simply want to contact us to request a new feature, please fill up the contact sheet! We would love to hear from you."
    );

    msgBox.exec();
}

void MainWindow::displayContact()
{
    ContactSheet *contact = new ContactSheet;

    contact->setAttribute(Qt::WA_DeleteOnClose);
    contact->show();
}

void MainWindow::adminPasswordAuth()
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
        prompt->setAttribute(Qt::WA_DeleteOnClose);
        prompt->show();
    }
}


void MainWindow::adminPasswordClear()
{
    this->ui->adminPwdInput->setText("");
}

void MainWindow::populateSortCells()
{
    int numOfEntries = footballTeams.size();

    for(int i = 1; i < numOfEntries; ++i)
    {
        QTableWidgetItem *item;

        for(int j = 0; j < 9; ++j)
        {
            item = new QTableWidgetItem;
            QString itemText = footballTeams[i].getDataFromIndex(j);
            item->setText(itemText);

            this->ui->tableWidget->setItem(i - 1, j, item);
        }
    }
}
