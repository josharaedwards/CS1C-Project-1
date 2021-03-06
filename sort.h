#ifndef SORT_H
#define SORT_H

#include "football.h"

//Enum for the different sorting types
enum SortType{team, stadium, seating, location, league};

void sort(QVector<Football> footballTeams, int numOfEntries, SortType sortBy);

void sortByTeam(QVector<Football> footballTeams, int numOfEntries);

void sortByStadium(QVector<Football> footballTeams, int numOfEntries);

void sortBySeating(QVector<Football> footballTeams, int numOfEntries);

void sortByLocation(QVector<Football> footballTeams, int numOfEntries);

void sortByLeague(QVector<Football> footballTeams, int numOfEntries);

bool isGreaterThan(QString first, QString second);

bool isGreaterThan(int first, int second);

int totalCapacity(QVector<Football> footballTeams, int numOfEntries);

void SortRoofType(QVector<Football> footballTeams, int numOfEntries);

#endif // SORT_H


