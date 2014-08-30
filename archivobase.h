#ifndef ARCHIVOBASE_H
#define ARCHIVOBASE_H
#include <QString>
#include <QDate>
#include<iostream>
using namespace std;

class ArchivoBase
{
public:
    int size;
    QString nombre, path, tipo;
    QDate Fecha_creacion, Fecha_mod;
    ArchivoBase();
};

#endif // ARCHIVOBASE_H
