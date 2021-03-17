#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "football.h"
#include "sort.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void loadDataFromFile(QString fileName);
    void populateSortCells(QVector<Football> teamList);
    SortType stringToEnum(QString text);
    void totalUpdate(QVector<Football> footballTeam);

public slots:
    void displayAdmin();
    void displayHome();
    void displaySort();
    void displayHelp();
    void displayContact();
    void onFilterClick();
    void onSortClick();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
