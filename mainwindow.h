#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 *  @file MainWindow.h
 *  @brief GUI structure
 */

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

    ///@brief load data from file
    ///
    ///@param fileName Especific file to read from

    void loadDataFromFile(QString fileName);

    /// @brief Organizes data in table widget
    ///
    /// @param teamList

    void populateSortCells(QVector<Football> teamList);
    ///
    /// \brief Sot data according team`s name, stadium`s name, location and seating cpacity
    /// \param text
    /// \return The selection made by user
    ///
    SortType stringToEnum(QString text);
    ///
    /// \brief Displays the total capacity
    /// \param footballTeam
    ///
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
