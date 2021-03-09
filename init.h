#ifndef INIT_H
#define INIT_H

#include "football.h"
#include "sort.h"
#include <iostream>
#include <QDataStream>

void fileRead(QVector<Football> &arr, QDataStream &fin);

#endif // INIT_H
