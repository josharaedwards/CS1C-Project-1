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
QVector<Football> sortedTeams;
QVector<Football> leagueTeams;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->displayHome();
    ui->loginPanel->raise();

    footballTeams =  fileRead("C:/Users/Channel 3/Documents/GitHub/CS1C-Project-1/NFL Information.tsv");
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

    populateSortCells(footballTeams);

    for(int i = 0; i < numOfEntries; ++i)
    {
        sortedTeams.push_back(footballTeams[i]);
    }

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

void MainWindow::populateSortCells(QVector<Football> teamList)
{
    int numOfEntries = teamList.size();

    for(int i = 1; i < numOfEntries; ++i)
    {
        QTableWidgetItem *item;

        for(int j = 0; j < 9; ++j)
        {
            item = new QTableWidgetItem;
            QString itemText = teamList[i].getDataFromIndex(j);
            item->setText(itemText);

            this->ui->tableWidget->setItem(i - 1, j, item);
        }
    }
}

void MainWindow::onFilterClick()
{
    QString filterBy = this->ui->dataFilterDropdown->currentText();

    if(filterBy == "National Football League (NFL)")
    {
        leagueTeams = displayByLeague(sortedTeams, true);
        this->ui->tableWidget->setRowCount(leagueTeams.size());
        populateSortCells(leagueTeams);
    }
    else if(filterBy == "American Football Conference (AFC)")
    {
        leagueTeams = displayByLeague(sortedTeams, false);
        this->ui->tableWidget->setRowCount(leagueTeams.size());
        populateSortCells(leagueTeams);
    }
    else
    {
        this->ui->tableWidget->setRowCount(sortedTeams.size());
        populateSortCells(sortedTeams);
    }
}

SortType MainWindow::stringToEnum(QString text)
{
    if(text == "Team Name")
    {
        return team;
    }
    else if(text == "Stadium Name")
    {
        return stadium;
    }
    else if(text == "Seating Capacity")
    {
        return seating;
    }
    else if(text == "Location")
    {
        return location;
    }

    //If we have an unpredictable string
    return team;
}

void MainWindow::onSortClick()
{
    QString sortBy = this->ui->dataSortDropdown->currentText();

    sortedTeams = sort(footballTeams, stringToEnum(sortBy));

    this->ui->tableWidget->setRowCount(sortedTeams.size());

    populateSortCells(sortedTeams);
}
