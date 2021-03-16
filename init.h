#ifndef INIT_H
#define INIT_H

#include "football.h"
#include "sort.h"

///@param Filename is the file provide by the programmer for the program to read from
///@return An array named footballTeam with the data from the file
vector<Football> fileRead(QString fileName);

Football processLine(Football tempTeam, QString line);

Football updateFootballInfo(Football& tempTeam, QStringList list, int num);

#endif // INIT_H
