#include <QtDebug>
#include "sort.h"

QVector<Football> sort(QVector<Football> footballTeams, SortType sortBy)
{   
    switch(sortBy)
    {
    case team:
        footballTeams = sortByTeam(footballTeams);
        break;
    case stadium:
        footballTeams = sortByStadium(footballTeams);
        break;
    case seating:
        footballTeams = sortBySeating(footballTeams);
        break;
    case location:
        footballTeams = sortByLocation(footballTeams);
        break;
    case league:
        footballTeams = sortByLocation(footballTeams);
        break;
    case rooftype:
        footballTeams = sortByRoofType(footballTeams);
        break;
    }

    return footballTeams;
}

QVector<Football> sortByTeam(QVector<Football> footballTeams)
{
    int numOfEntries = footballTeams.size();

    for(int i = 1; i < numOfEntries - 1; ++i)
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

    for(int i = 1; i < numOfEntries - 1; ++i)
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

    for(int i = 1; i < numOfEntries - 1; ++i)
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

    for(int i = 1; i < numOfEntries - 1; ++i)
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

QVector<Football> sortByRoofType(QVector<Football> footballTeams)
{
    int numOfEntries = footballTeams.size();

    for(int i = 1; i < numOfEntries - 1; ++i)
    {
        for(int j = i + 1; j < numOfEntries; ++j)
        {
            bool result = isGreaterThan(footballTeams[i].getStadiumRoofType(), footballTeams[j].getStadiumRoofType());
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

QVector<Football> displayByLeague(QVector<Football> defaultTeamList, bool bIsNFC)
{
    QVector<Football> updatedList;

    int numOfEntries = defaultTeamList.size();

    for(int i = 0; i <numOfEntries; i++)
    {
        if(bIsNFC)
        {
            if(defaultTeamList[i].getConference() == "National Football Conference")
            {
                updatedList.push_back(defaultTeamList[i]);
            }
        }
        else
        {
            if(defaultTeamList[i].getConference() == "American Football Conference")
            {
                updatedList.push_back(defaultTeamList[i]);
            }
        }
    }

    return updatedList;
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
    int num = 0;
    int sum = 0;

    for (int i = 0; i < numOfEntries; i++)
    {
        QString seatingCapacity = footballTeams[i].getSeatingCapacity();
        num = seatingCapacity.toInt();
        sum += num;
    }

    return sum;
}


