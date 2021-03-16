#ifndef SORT_H
#define SORT_H

#include "football.h"

//Enum for the different sorting types
enum SortType{team, stadium, seating, location, league, rooftype};

QVector<Football> sort(QVector<Football> footballTeams, SortType sortBy);

QVector<Football> sortByTeam(QVector<Football> footballTeams);

QVector<Football> sortByStadium(QVector<Football> footballTeams);

QVector<Football> sortBySeating(QVector<Football> footballTeams);

QVector<Football> sortByLocation(QVector<Football> footballTeams);

QVector<Football> sortByRoofType(QVector<Football> footballTeams);

QVector<Football> displayByLeague(QVector<Football> footballTeams, bool bIsNFL);

bool isGreaterThan(QString first, QString second);

bool isGreaterThan(int first, int second);

int totalCapacity(QVector<Football> footballTeams);

#endif // SORT_H


