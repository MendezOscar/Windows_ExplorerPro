#include "archivobase.h"
#include<iostream>
#include<QDate>
using namespace std;

ArchivoBase::ArchivoBase()
{
    this->Fecha_creacion = QDate::currentDate();
    this->Fecha_mod = QDate::currentDate();
}
