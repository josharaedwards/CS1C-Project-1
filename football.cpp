#include "football.h"

Football::Football()
{
    teamName = "None";
    stadiumName = "None";
    seatingCapacity = 0;
    location = "None";
    conference = "None";
    division = "None";
    surfaceType = "None";
    stadiumRoofType = "None";
    dateOpened = 0;
}

Football::Football(QString oTN, QString oSN, int oSC, QString oL, QString oC, QString oD, QString oST, QString oSRT, int oDO)
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

void Football::setSeatingCapacity(int oSC)
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

void Football::setDateOpened(int oDO)
{
    dateOpened = oDO;
}
