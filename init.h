#ifndef INIT_H
#define INIT_H
/**
 *  @file init.h
 *  @brief Read from file and initilizes program
 */
#include "football.h"
#include "sort.h"

///@brief read from file
///@param Filename
///@return An array named footballTeam with the data from the file
QVector<Football> fileRead(QString fileName);
///@brief updates Football information
Football processLine(Football tempTeam, QString line);
///@brief updates Football information acoording to the sort request
Football updateFootballInfo(Football& tempTeam, QStringList list, int num);

#endif // INIT_H
