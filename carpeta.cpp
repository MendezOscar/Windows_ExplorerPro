#include "carpeta.h"
#include<iostream>
using namespace std;

Carpeta::Carpeta(QString nombre, QString path) : ArchivoBase()
{
    this->Ab = new Lista<ArchivoBase*>();
    this->nombre = nombre;
    this->path = path;
    this->tipo = "C";
    this->size = 4;
}

Carpeta *Carpeta::agregarCarpeta(QString nombre, QString path)
{
    Carpeta * Car = new Carpeta(nombre, path);
    Ab->inserta(Car);
    return 0;
}

Carpeta *Carpeta::buscarCarpeta(QString nombre)
{
    Nodo<ArchivoBase*>* nodo = this->Ab->primero();
    while(nodo != NULL){
      if(nodo->valor->nombre == nombre)
          if(nodo->valor->tipo == "C")
           return new Carpeta(nombre,nodo->valor->path);
        nodo = Ab->siguiente(nodo);
   }
   return NULL;
}
