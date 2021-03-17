/**
 *  @file football.h
 *  @brief holds and handle the data
 */

#ifndef FOOTBALL_H
#define FOOTBALL_H

#include <QString>
#include <QVector>
#include <fstream>
#include <iostream>
#include <string>
#include <QDataStream>
#include <QFile>
#include <QTextStream>
using namespace std;

///@class Football class
class Football
{
    QString teamName;
    QString stadiumName;
    QString seatingCapacity;
    QString location;
    QString conference;
    QString division;
    QString surfaceType;
    QString stadiumRoofType;
    QString dateOpened;

public:
    ///Default constructor
    Football();
    /// @brief Constructor with parameters
    /// @param oTN The team`s name
    ///
    /// @param oSN The stadium `s name
    ///
    /// @param oSC The stadium`s seating capacity
    ///
    /// @param oL The stadium`s location
    ///
    /// @param oC The stadium`s conference
    ///
    /// @param oD The stadium`s division
    ///
    /// @param oST The stadium`s surface type
    ///
    /// @param oSRT The stadium`s roof type
    ///
    /// @param oDO The stadium`s open date
    Football(QString oTN, QString oSN, QString oSC, QString oL, QString oC, QString oD, QString oST, QString oSRT, QString oDO);

    ///@brief Setter for the team`s name
    ///
    /// @param oTN team`s name
    void setTeamName(QString oTN);
    ///@brief Setter for the stadium`s name
    ///
    /// @param oSN The stadium `s name
    void setStadiumName(QString oSN);
    ///Setter for the seating capacity
    ///
    /// @param oSC The stadium`s seating capacity
    void setSeatingCapacity(QString oSC);
    ///@brief Setter for stadium`s location
    ///
    /// @param oL The stadium `s location
    void setLocation(QString oL);
    ///@brief Setter for the stadium`s conference
    ///
    /// @param oC The stadium`s conference
    void setConference(QString oC);
    ///@brief Setter for the stadium`s divison
    ///
    /// @param oD The stadium`s division
    void setDivision(QString oD);
    ///@brief Setter for the stadium`s surface type
    ///
    /// @param oST The stadium`s surface type
    void setSurfaceType(QString oST);
    ///@brief Setter for the stadium`s roof type
    ///
    /// @param oSRT The stadium`s roof type
    void setStadiumRoofType(QString oSRT);
    ///@brief Setter for the stadium`s date open
    ///
    /// @param oDO The stadium`s open date
    void setDateOpened(QString oDO);

    ///Getter for the team`s name
    ///
    /// @return team`s name
    QString getTeamName();
    ///Getter for the stadium`s name
    ///
    /// @return the stadium`s name
    QString getStadiumName();
    ///Getter for the stadium`s seating capactity
    ///
    /// @return the stadium`s seating capactity
    QString getSeatingCapacity();
    ///Getter for the stadium`s location
    ///
    /// @return the stadium`s location
    QString getLocation();
    ///Getter for the stadium`s conference
    ///
    /// @return The stadium`s conference
    QString getConference();
    ///Getter for the stadium`s division
    ///
    /// @return the stadium`s division
    QString getDivision();
    ///Getter for the stadium`s surface type
    ///
    /// @return the stadium`s surface type
    QString getSurfaceType();
    ///Getter for the stadium`s roof type
    ///
    /// @return the stadium`s roof type
    QString getStadiumRoofType();
    ///Getter for the stadium`s open date
    ///
    /// @return the stadium`s open date
    QString getDateOpened();
    QString getDataFromIndex(int num);
};

#endif // FOOTBALL_H
