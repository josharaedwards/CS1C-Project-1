#include <QtDebug>
#include "sort.h"

QVector<Football> sort(QVector<Football> footballTeams, SortType sortBy)
{   
    switch(sortBy)
    {
    case team:
        sortByTeam(footballTeams);
        break;
    case stadium:
        sortByStadium(footballTeams);
        break;
    case seating:
        sortBySeating(footballTeams);
        break;
    case location:
        sortByLocation(footballTeams);
        break;
    case league:
        sortByLocation(footballTeams);
        break;
    case rooftype:
        sortByRoofType(footballTeams);
        break;
    }

    return footballTeams;
}

QVector<Football> sortByTeam(QVector<Football> footballTeams)
{
    int numOfEntries = footballTeams.size();

    for(int i = 0; i < numOfEntries - 1; ++i)
    {
        for(int j = i + 1; j < numOfEntries; ++j)
        {
            bool result = isGreaterThan(footballTeams[i].getTeamName(), footballTeams[j].getTeamName());
            Football temp;

            if(result)
            {
                temp = footballTeams[i];
                footballTeams[i] = footballTeams[j];
                footballTeams[j] = temp;
            }
        }
    }

    return footballTeams;
}

QVector<Football> sortByStadium(QVector<Football> footballTeams)
{
    int numOfEntries = footballTeams.size();

    for(int i = 0; i < numOfEntries - 1; ++i)
    {
        for(int j = i + 1; j < numOfEntries; ++j)
        {
            bool result = isGreaterThan(footballTeams[i].getStadiumName(), footballTeams[j].getStadiumName());
            Football temp;

            if(result)
            {
                temp = footballTeams[i];
                footballTeams[i] = footballTeams[j];
                footballTeams[j] = temp;
            }
        }
    }

    return footballTeams;
}

QVector<Football> sortBySeating(QVector<Football> footballTeams)
{
    int numOfEntries = footballTeams.size();

    for(int i = 0; i < numOfEntries - 1; ++i)
    {
        for(int j = i + 1; j < numOfEntries; ++j)
        {
            bool result = isGreaterThan(footballTeams[i].getSeatingCapacity(), footballTeams[j].getSeatingCapacity());
            Football temp;

            if(result)
            {
                temp = footballTeams[i];
                footballTeams[i] = footballTeams[j];
                footballTeams[j] = temp;
            }
        }
    }

    return footballTeams;
}

QVector<Football> sortByLocation(QVector<Football> footballTeams)
{
    int numOfEntries = footballTeams.size();

    for(int i = 0; i < numOfEntries - 1; ++i)
    {
        for(int j = i + 1; j < numOfEntries; ++j)
        {
            bool result = isGreaterThan(footballTeams[i].getLocation(), footballTeams[j].getLocation());
            Football temp;

            if(result)
            {
                temp = footballTeams[i];
                footballTeams[i] = footballTeams[j];
                footballTeams[j] = temp;
            }
        }
    }

    return footballTeams;
}

bool isGreaterThan(QString first, QString second)
{
    QChar firstLetter = first[0];
    QChar secondLetter = second[0];

    if(firstLetter > secondLetter)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isGreaterThan(int first, int second)
{
    if(first > second)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int totalCapacity(QVector<Football> footballTeams)
{
    int numOfEntries = footballTeams.size();
    int sum = 0;

    for (int i = 0; i < numOfEntries; i++)
    {
        QString seatingCapacity = footballTeams[i].getSeatingCapacity();
        int num = seatingCapacity.toInt();
        sum += num;
    }

    return sum;
}

QVector<Football> sortByRoofType(QVector<Football> footballTeams)
{
    //choose stadium Roof type
    QString roofType;

    int numOfEntries = footballTeams.size();

    for(int i = 0; i <numOfEntries; i++)
    {
        if(footballTeams[i].getStadiumRoofType() == roofType)
        {
             //QTextStream(stdout) << footballTeams[i].getStadiumName() << "   " << footballTeams[i].getStadiumRoofType();
        }
    }

    return footballTeams;
}

QVector<Football> sortByLeague(QVector<Football> footballTeams)
{
    //choose by league NFL or AFC
    QString selectedLeague;

    int numOfEntries = footballTeams.size();

    for(int i = 0; i <numOfEntries; i++)
    {
        if(footballTeams[i].getDivision() == selectedLeague)
        {
            //QTextStream(stdout) <<footballTeams[i].getDivision() << " " << footballTeams[i].getTeamName() << " " << footballTeams[i].getStadiumName() << " " << footballTeams[i].getSeatingCapacity() << " " << footballTeams[i].getLocation() << " " << footballTeams[i].getConference() << " " << footballTeams[i].getSurfaceType() << " " << footballTeams[i].getStadiumRoofType() << " " << footballTeams[i].getDateOpened();

        }
    }

    return footballTeams;
}
