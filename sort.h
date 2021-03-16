/**
 *  @file sort.h
 *  @brief Functions to organize the data read from file
 *
 */

#ifndef SORT_H
#define SORT_H

#include "football.h"

///Enum
///Handle the user`s choices to filter the search
enum SortType{team, stadium, seating, location, league, rooftype};

///The following functions prototypes sort the data according user choices.
///Parameters: Qvector <Football> Dynamic array

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


