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

Football::Football(string oTN, string oSN, string oSC, string oL, string oC, string oD, string oST, string oSRT, string oDO)
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

void Football::setTeamName(string oTN)
{
    teamName = oTN;
}

void Football::setStadiumName(string oSN)
{
    stadiumName = oSN;
}

void Football::setSeatingCapacity(string oSC)
{
    seatingCapacity = oSC;
}

void Football::setLocation(string oL)
{
    location = oL;
}

void Football::setConference(string oC)
{
    conference = oC;
}

void Football::setDivision(string oD)
{
    division = oD;
}

void Football::setSurfaceType(string oST)
{
    surfaceType = oST;
}

void Football::setStadiumRoofType(string oSRT)
{
    stadiumRoofType = oSRT;
}

void Football::setDateOpened(string oDO)
{
    dateOpened = oDO;
}

string Football::getTeamName()
{
    return teamName;
}

string Football::getStadiumName()
{
    return stadiumName;
}

string Football::getSeatingCapacity()
{
    return seatingCapacity;
}

string Football::getLocation()
{
    return location;
}

string Football::getConference()
{
    return conference;
}

string Football::getDivision()
{
    return division;
}

string Football::getSurfaceType()
{
    return surfaceType;
}

string Football::getStadiumRoofType()
{
    return stadiumRoofType;
}

string Football::getDateOpened()
{
    return dateOpened;
}
