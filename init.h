#ifndef INIT_H
#define INIT_H

#include "football.h"
#include "sort.h"

vector<Football> fileRead(QString fileName);

Football processLine(Football tempTeam, QString line);

Football updateFootballInfo(Football& tempTeam, QStringList list, int num);

#endif // INIT_H
