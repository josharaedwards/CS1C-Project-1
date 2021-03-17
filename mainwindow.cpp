#include "mainwindow.h"
#include "contactsheet.h"
#include "adminpanel.h"
#include "helppanel.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "ui_contactsheet.h"
#include "ui_adminpanel.h"
#include "ui_helppanel.h"
#include "ui_dialog.h"
#include "init.h"

//Global Football Teams Data Holders
QVector<Football> footballTeams;
QVector<Football> sortedTeams;
QVector<Football> leagueTeams;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    footballTeams = fileRead(":/data/data/NFL Information.tsv");

    int numOfEntries = footballTeams.size();

    this->ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->ui->tableWidget->setRowCount(numOfEntries);

    populateSortCells(footballTeams);

    for(int i = 0; i < numOfEntries; ++i)
    {
        sortedTeams.push_back(footballTeams[i]);
    }

    totalUpdate(sortedTeams);

    this->displayHome();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAdmin()
{
    AdminPanel *adminPanel = new AdminPanel;

    adminPanel->setWindowTitle("Upload");
    adminPanel->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    adminPanel->setAttribute(Qt::WA_DeleteOnClose);
    adminPanel->show();

    QObject::connect(adminPanel, &AdminPanel::newFileLoaded, this, &MainWindow::loadDataFromFile);
}

void MainWindow::displayHome()
{
    this->ui->homeBtn->setStyleSheet("border:none; background-color: rgb(236, 239, 244); color: rgb(46, 52, 64);");
    this->ui->sortBtn->setStyleSheet("border:none; background-color: rgb(46, 52, 64); color: rgb(236, 239, 244);");
    this->ui->homeContent->raise();
}

void MainWindow::displaySort()
{
    this->ui->homeBtn->setStyleSheet("border:none; background-color: rgb(46, 52, 64); color: rgb(236, 239, 244);");
    this->ui->sortBtn->setStyleSheet("border:none; background-color: rgb(236, 239, 244); color: rgb(46, 52, 64);");
    this->ui->sortContent->raise();
}

void MainWindow::displayHelp()
{
    HelpPanel *help = new HelpPanel;

    help->setWindowTitle("Navigating this pamphlet");
    help->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    help->setAttribute(Qt::WA_DeleteOnClose);
    help->show();
}

void MainWindow::displayContact()
{
    ContactSheet *contact = new ContactSheet;

    contact->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    contact->setAttribute(Qt::WA_DeleteOnClose);
    contact->show();
}

void MainWindow::loadDataFromFile(QString fileName)
{
    footballTeams = fileRead(fileName);

    this->ui->tableWidget->setRowCount(footballTeams.size());

    populateSortCells(footballTeams);

    sortedTeams.empty();

    int numOfEntries = footballTeams.size();

    for(int i = 0; i < numOfEntries; ++i)
    {
        sortedTeams.push_back(footballTeams[i]);
    }

    totalUpdate(sortedTeams);
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
        totalUpdate(leagueTeams);
    }
    else if(filterBy == "American Football Conference (AFC)")
    {
        leagueTeams = displayByLeague(sortedTeams, false);
        this->ui->tableWidget->setRowCount(leagueTeams.size());
        populateSortCells(leagueTeams);
        totalUpdate(leagueTeams);
    }
    else
    {
        this->ui->tableWidget->setRowCount(sortedTeams.size());
        populateSortCells(sortedTeams);
        totalUpdate(sortedTeams);
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

    totalUpdate(sortedTeams);
}

void MainWindow::totalUpdate(QVector<Football> footballTeam)
{
    int totalDisplay = totalCapacity(footballTeam);

    this->ui->totalCapacityDisplay->setText(QString::number(totalDisplay).append(totalDisplay > 1 ? " seats" : " seat"));
}
