#ifndef CARPETA_H
#define CARPETA_H
#include "Lista.h"
#include "archivobase.h"

#include <iostream>
using namespace std;

class Carpeta : public ArchivoBase
{
public:
    Lista <ArchivoBase*>* Ab;
    Carpeta(QString nombre, QString path);
    Carpeta *agregarCarpeta(QString nombre, QString path);
    Carpeta *buscarCarpeta(QString nombre);
};

#endif // CARPETA_H
