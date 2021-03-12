#ifndef FOOTBALL_H
#define FOOTBALL_H

#include <QString>
#include <QVector>
#include <fstream>
#include <iostream>
#include <string>
#include <QDataStream>
using namespace std;

class Football
{
    string teamName;
    string stadiumName;
    string seatingCapacity;
    string location;
    string conference;
    string division;
    string surfaceType;
    string stadiumRoofType;
    string dateOpened;

public:
    Football();
    Football(string oTN, string oSN, string oSC, string oL, string oC, string oD, string oST, string oSRT, string oDO);

    void setTeamName(string oTN);
    void setStadiumName(string oSN);
    void setSeatingCapacity(string oSC);
    void setLocation(string oL);
    void setConference(string oC);
    void setDivision(string oD);
    void setSurfaceType(string oST);
    void setStadiumRoofType(string oSRT);
    void setDateOpened(string oDO);

    string getTeamName();
    string getStadiumName();
    string getSeatingCapacity();
    string getLocation();
    string getConference();
    string getDivision();
    string getSurfaceType();
    string getStadiumRoofType();
    string getDateOpened();
};

#endif // FOOTBALL_H
