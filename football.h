/**
 *  @file football.h
 *  @brief class Football and prototypes
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

///Holds and organizes the data read from file
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
    Football();
    Football(QString oTN, QString oSN, QString oSC, QString oL, QString oC, QString oD, QString oST, QString oSRT, QString oDO);
    /// @param oTN Team name
    void setTeamName(QString oTN);
    ///@param oSN Stadium name
    void setStadiumName(QString oSN);
    ///@param oSC Seating capacity
    void setSeatingCapacity(QString oSC);
    ///@param oL Location
    void setLocation(QString oL);
    ///@param oC Conference
    void setConference(QString oC);
    ///@param oD Division
    void setDivision(QString oD);
    ///@param oST Surface Type
    void setSurfaceType(QString oST);
    ///@param oSRT Stadium roof type
    void setStadiumRoofType(QString oSRT);
    ///@param oDO Date Opened
    void setDateOpened(QString oDO);

    QString getTeamName();
    QString getStadiumName();
    QString getSeatingCapacity();
    QString getLocation();
    QString getConference();
    QString getDivision();
    QString getSurfaceType();
    QString getStadiumRoofType();
    QString getDateOpened();

    QString getDataFromIndex(int num);
};

#endif // FOOTBALL_H
