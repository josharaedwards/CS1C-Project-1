#ifndef FOOTBALL_H
#define FOOTBALL_H

#include <QString>

class Football
{
    QString teamName;
    QString stadiumName;
    int seatingCapacity;
    QString location;
    QString conference;
    QString division;
    QString surfaceType;
    QString stadiumRoofType;
    int dateOpened;

public:
    Football();
    Football(QString oTN, QString oSN, int oSC, QString oL, QString oC, QString oD, QString oST, QString oSRT, int oDO);

    void setTeamName(QString oTN);
    void setStadiumName(QString oSN);
    void setSeatingCapacity(int oSC);
    void setLocation(QString oL);
    void setConference(QString oC);
    void setDivision(QString oD);
    void setSurfaceType(QString oST);
    void setStadiumRoofType(QString oSRT);
    void setDateOpened(int oDO);
};

#endif // FOOTBALL_H
