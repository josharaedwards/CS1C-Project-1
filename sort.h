#ifndef SORT_H
#define SORT_H

#include "football.h"

enum SortType{team, stadium, seating, location};

void sort(Football footballTeams[], int numOfEntries, SortType sortBy);

void sortByTeam(Football footballTeams[], int numOfEntries);

void sortByStadium(Football footballTeams[], int numOfEntries);

void sortBySeating(Football footballTeams[], int numOfEntries);

void sortByLocation(Football footballTeams[], int numOfEntries);

bool isGreaterThan(QString first, QString second);

bool isGreaterThan(int first, int second);

#endif // SORT_H
