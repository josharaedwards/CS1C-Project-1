/**
 *  @file sort.h
 *  @brief Functions to organize and sort the data read from file
 *
 */

#ifndef SORT_H
#define SORT_H

#include "football.h"

///@brief Handles the user`s choices to filter the search
enum SortType{team, stadium, seating, location, league, rooftype};

///@param footballTeams Dynamic array
///
/// @param sortBy User selection

QVector<Football> sort(QVector<Football> footballTeams, SortType sortBy);
///@brief sort data by team
///
///@param footballTeams Dynamic array

QVector<Football> sortByTeam(QVector<Football> footballTeams);
///@brief sort data by stadium
///
///@param footballTeams Dynamic array

QVector<Football> sortByStadium(QVector<Football> footballTeams);
///@brief sort data by seating capacity
///
///@param footballTeams Dynamic array
QVector<Football> sortBySeating(QVector<Football> footballTeams);
///@brief sort data by location
///
///@param footballTeams Dynamic array

QVector<Football> sortByLocation(QVector<Football> footballTeams);
///@brief sort data by roof type
///
///@param footballTeams Dynamic array
QVector<Football> sortByRoofType(QVector<Football> footballTeams);
///@brief sort data by football league
///
///@param footballTeams Dynamic array
///@param boolean that selects for NFL true and AFL false
QVector<Football> displayByLeague(QVector<Football> footballTeams, bool bIsNFL);

///@brief Organized data alphabetically
bool isGreaterThan(QString first, QString second);
///@brief Organized int data alphabetically
bool isGreaterThan(int first, int second);

///@brief sort by stadiums
bool find(QVector<QString> stadiums, QString compare);
///@brief Display the total capacit
int totalCapacity(QVector<Football> footballTeams);

#endif // SORT_H


