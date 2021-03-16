/**
 *  @file init.h
 *  @brief Functions for: read from file, initialization from a file and updating data
 *
 */

#include "init.h"

QVector<Football> fileRead(QString fileName)
{
    QVector<Football> footballTeams;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return footballTeams;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line;
        Football tempTeam;

        line = in.readLine();

        tempTeam = processLine(tempTeam, line);

        footballTeams.push_back(tempTeam);
    }

    return footballTeams;
}

Football processLine(Football tempTeam, QString line)
{
    QStringList list;

    list = line.split('\t');
    int size = list.size();

    for(int i = 0; i < size; ++i)
    {
        updateFootballInfo(tempTeam, list, i);
    }

    return tempTeam;
}

Football updateFootballInfo(Football& tempTeam, QStringList list, int num)
{
    if(list[num] == "")
    {
        return tempTeam;
    }

    switch(num)
    {
    case 0:
        tempTeam.setTeamName(list[num]);
        break;
    case 1:
        tempTeam.setStadiumName(list[num]);
        break;
    case 2:
        tempTeam.setSeatingCapacity(list[num]);
        break;
    case 3:
        tempTeam.setLocation(list[num]);
        break;
    case 4:
        tempTeam.setConference(list[num]);
        break;
    case 5:
        tempTeam.setDivision(list[num]);
        break;
    case 6:
        tempTeam.setSurfaceType(list[num]);
        break;
    case 7:
        tempTeam.setStadiumRoofType(list[num]);
        break;
    case 8:
        tempTeam.setDateOpened(list[num]);
        break;
    default:
        cout << "Warning: Football Info Out Of Scope!" << endl;
        break;
    }

    return tempTeam;
}
