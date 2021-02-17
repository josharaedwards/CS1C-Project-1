#include "sort.h"

void sort(Football footballTeams[], int numOfEntries, SortType sortBy)
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
    }
}

void sortByTeam(Football footballTeams[], int numOfEntries)
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

void sortByStadium(Football footballTeams[], int numOfEntries)
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

void sortBySeating(Football footballTeams[], int numOfEntries)
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

void sortByLocation(Football footballTeams[], int numOfEntries)
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
