#include <QtDebug>
#include "sort.h"

void sort(QVector<Football> footballTeams, int numOfEntries, SortType sortBy)
{
    switch(sortBy)
    {
    case team:
        sortByTeam(footballTeams, numOfEntries);
        break;
    case stadium:
        sortByStadium(footballTeams, numOfEntries);
        break;
    case seating:
        sortBySeating(footballTeams, numOfEntries);
        break;
    case location:
        sortByLocation(footballTeams, numOfEntries);
        break;
    case league:
        sortByLocation(footballTeams, numOfEntries);
        break;

    }
}

void sortByTeam(QVector<Football> footballTeams, int numOfEntries)
{
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
}

void sortByStadium(QVector<Football> footballTeams, int numOfEntries)
{
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
}

void sortBySeating(QVector<Football> footballTeams, int numOfEntries)
{
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
}

void sortByLocation(QVector<Football> footballTeams, int numOfEntries)
{
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
}

bool isGreaterThan(QString first, QString second)
{
    QCharRef firstLetter = first[0];
    QCharRef secondLetter = second[0];

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

int totalCapacity(QVector<Football> footballTeams, int numOfEntries)
{
    int sum = 0;

    for (int i = 0; i < numOfEntries; i++)
    {
        sum += footballTeams[i].getSeatingCapacity();
    }

    return sum;
}

void SortRoofType(QVector<Football> footballTeams, int numOfEntries)
{
    //choose stadium Roof type
    QString roofType;

    for(int i = 0; i <numOfEntries; i++)
    {
        if(footballTeams[i].getStadiumRoofType() == roofType)
        {
             QTextStream(stdout) << footballTeams[i].getStadiumName() << "   " << footballTeams[i].getStadiumRoofType();
        }
    }
}

void sortByLeague(QVector<Football> footballTeams, int numOfEntries)
{
    //choose by league NFL or AFC
    QString selectedLeague;

    for(int i = 0; i <numOfEntries; i++)
    {
        if(footballTeams[i].getDivision() == selectedLeague)
        {
            QTextStream(stdout) <<footballTeams[i].getDivision() << " " << footballTeams[i].getTeamName() << " " << footballTeams[i].getStadiumName() << " " << footballTeams[i].getSeatingCapacity() << " " << footballTeams[i].getLocation() << " " << footballTeams[i].getConference() << " " << footballTeams[i].getSurfaceType() << " " << footballTeams[i].getStadiumRoofType() << " " << footballTeams[i].getDateOpened();

        }
    }
}
