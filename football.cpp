#include "football.h"

Football::Football()
{
    teamName = "None";
    stadiumName = "None";
    seatingCapacity = "0";
    location = "None";
    conference = "None";
    division = "None";
    surfaceType = "None";
    stadiumRoofType = "None";
    dateOpened = "0";
}
Football::Football(QString oTN, QString oSN, QString oSC, QString oL, QString oC, QString oD, QString oST, QString oSRT, QString oDO)
{
    teamName = oTN;
    stadiumName = oSN;
    seatingCapacity = oSC;
    location = oL;
    conference = oC;
    division = oD;
    surfaceType = oST;
    stadiumRoofType = oSRT;
    dateOpened = oDO;
}

void Football::setTeamName(QString oTN)
{
    teamName = oTN;
}

void Football::setStadiumName(QString oSN)
{
    stadiumName = oSN;
}

void Football::setSeatingCapacity(QString oSC)
{
    seatingCapacity = oSC;
}

void Football::setLocation(QString oL)
{
    location = oL;
}

void Football::setConference(QString oC)
{
    conference = oC;
}

void Football::setDivision(QString oD)
{
    division = oD;
}

void Football::setSurfaceType(QString oST)
{
    surfaceType = oST;
}

void Football::setStadiumRoofType(QString oSRT)
{
    stadiumRoofType = oSRT;
}

void Football::setDateOpened(QString oDO)
{
    dateOpened = oDO;
}

QString Football::getTeamName()
{
    return teamName;
}

QString Football::getStadiumName()
{
    return stadiumName;
}

QString Football::getSeatingCapacity()
{
    return seatingCapacity;
}

QString Football::getLocation()
{
    return location;
}

QString Football::getConference()
{
    return conference;
}

QString Football::getDivision()
{
    return division;
}

QString Football::getSurfaceType()
{
    return surfaceType;
}

QString Football::getStadiumRoofType()
{
    return stadiumRoofType;
}

QString Football::getDateOpened()
{
    return dateOpened;
}

///switch statement that organizes the data according user`s choices
///Parameter: "num" is the choice made by user
QString Football::getDataFromIndex(int num)
{
    QString data;

    switch(num)
    {
    case 0:
       data = teamName;
       break;
    case 1:
       data = stadiumName;
       break;
    case 2:
       data = seatingCapacity;
       break;
    case 3:
       data = location;
       break;
    case 4:
       data = conference;
       break;
    case 5:
       data = division;
       break;
    case 6:
       data = surfaceType;
       break;
    case 7:
       data = stadiumRoofType;
       break;
    case 8:
       data = dateOpened;
       break;
    default:
       data = " ";
       break;
    }

    return data;
}
