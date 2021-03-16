/**
 *  @file mainwindow.h
 *  @brief Declares and specifies the widgets and slots for the GUI
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "football.h"
#include "sort.h"

///GUI main page
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void populateSortCells(QVector<Football> teamList);
    SortType stringToEnum(QString text);

public slots:
    void displayAdmin();
    void displayHome();
    void displaySort();
    void displayHelp();
    void displayContact();
    void adminPasswordAuth();
    void adminPasswordClear();

    void onFilterClick();
    void onSortClick();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
