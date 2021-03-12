#ifndef INIT_H
#define INIT_H

#include "football.h"
#include "sort.h"

QVector<Football> fileRead(string fileName);

Football updateFromFile(ifstream& myFile, int lineNum, Football tempTeam);

#endif // INIT_H
