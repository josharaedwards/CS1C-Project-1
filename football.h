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

    void setTeamName(QString oTN);
    void setStadiumName(QString oSN);
    void setSeatingCapacity(QString oSC);
    void setLocation(QString oL);
    void setConference(QString oC);
    void setDivision(QString oD);
    void setSurfaceType(QString oST);
    void setStadiumRoofType(QString oSRT);
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
