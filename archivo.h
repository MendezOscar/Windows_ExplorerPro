#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "Lista.h"
#include "archivobase.h"

#include <iostream>
using namespace std;

class Archivo : public ArchivoBase
{
public:
    QString Extencion;
    Lista <ArchivoBase*>* Ab;
    Archivo(QString nombre, QString Extencion);
    void agregarArchivo(QString nombre, QString Extencion);
};

#endif // ARCHIVO_H
