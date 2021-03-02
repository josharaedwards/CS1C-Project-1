#ifndef INIT_H
#define INIT_H

#include "football.h"
#include "sort.h"
#include <iostream>
#include <QDataStream>

void stringGetter(QString &str);

void display(QVector<Football> arr);

void fileWrite(QVector<Football> arr, QDataStream &fout);
void fileRead(QVector<Football> &arr, QDataStream &fin);

void testInit();

#endif // INIT_H
