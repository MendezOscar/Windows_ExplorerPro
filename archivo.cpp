#include "archivo.h"
#include<QString>
#include <QDebug>
#include <qtreewidget.h>
#include<iostream>
using namespace std;

Archivo::Archivo(QString nombre, QString Extencion) : ArchivoBase()
{
    this->nombre = nombre;
    this->size = 2;
    this->tipo = "A";
    this->Ab = new Lista<ArchivoBase*>();
    this->Extencion = Extencion;
}

void Archivo::agregarArchivo(QString nombre, QString Extencion)
{
    Archivo * Arc = new Archivo(nombre, Extencion);
    Ab->inserta(Arc);
}
