#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include <QString>
#include "archivobase.h"
using namespace std;

template <class T>

class Lista
{
    public:
        int size;
        Nodo<T>* inicio;

        Lista();
        virtual ~Lista();
        void inserta(int posicion, T valor);
        void limpiar();
        void suprimir(int pos);
        void inserta(T valor);
        T buscar(int pos);
        T obtener(int pos);
        int Localiza(T valor);
        Nodo<T>* LocalizaNodo(T valor, int *posicion);
        Nodo<T>* siguiente(Nodo<T>* posicion);
        Nodo<T>* anterior(Nodo<T>* posicion);
        Nodo<T>* primero();

    protected:
    private:
};

template<class T>
Lista<T>::Lista()
{
    size = 0;
    inicio = NULL;
}

template<class T>
Lista<T>::~Lista()
{
    //dtor
}

template<class T>
T Lista<T>::buscar(int pos){
    if(pos<0 || pos>=this->size)
        return NULL;
    Nodo<T>*tmp = inicio;
    for(int i=0; i<pos;i++)
            tmp = tmp->siguiente;
    return tmp->valor;
}

template<class T>
void Lista<T>::inserta(T valor){
    inserta(this->size, valor);
}

template <class T>
int Lista<T>::Localiza(T valor)
{
   int pos=0;
   LocalizaNodo(valor, &pos);
   return pos;
}

template <class T>
Nodo<T>* Lista<T>::LocalizaNodo(T valor, int *posicion)
{
    *posicion = 0;
    for(Nodo<T>*temp = inicio; temp!= NULL; temp=temp->siguiente)
    {
        if(temp->valor == valor)
        {
            return temp;
        }
        (*posicion) ++;
    }
    *posicion = -1;
    return NULL;
}

template<class T>
T Lista<T>::obtener(int pos){

    if(pos>=length || pos<0)
        return N();
    Nodo<N>* puntero = inicio;
    for(int i = 0; i < pos; i++, puntero = puntero->next);
    current = puntero;
    return puntero->valor;
}

template<class T>
void Lista<T>::inserta(int posicion, T valor)
{
    if(posicion>size)
        return ;
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    if(posicion == 0)
    {
        if(size == 0)
        {
            inicio = nuevoNodo;
        }else
        {
            nuevoNodo->siguiente = inicio;
            inicio = nuevoNodo;
        }
        size++;
        return ;
    }
    Nodo<T>* tmp;
    int i = 0;
    for(tmp = inicio; tmp != NULL; tmp = tmp->siguiente)
    {
        if(i == posicion-1)
        {
            nuevoNodo->siguiente = tmp->siguiente;
            tmp->siguiente = nuevoNodo;
        }
        i++;
    }


    size++;
}

template<class T>
void Lista<T>::suprimir(int pos){
    if(pos<0 || pos>=this->size)
        return;
    Nodo<T>* tmp = inicio;
    for(int i =0 ; i<pos-1; i++){
        tmp = tmp->siguiente;
    }
    if(pos == 0){
        inicio = inicio->siguiente;
    }else if(pos == size-1){
        tmp->siguiente = NULL;
    }else{
        tmp->siguiente = tmp->siguiente->siguiente;
    }
    size--;
}

template<class T>
Nodo<T>* Lista<T>::siguiente(Nodo<T>* posicion)
{

    return posicion->siguiente;
}

template<class T>
Nodo<T>* Lista<T>::anterior(Nodo<T>* posicion)
{
    Nodo<T>* tmp = inicio;
    while(tmp->siguiente!=posicion)
    {
        tmp = tmp->siguiente;
    }
    return tmp;
}

template<class T>
void Lista<T>::limpiar(){
    inicio = NULL;
    this->size=0;
}

template<class T>
Nodo<T>* Lista<T>::primero()
{
    return inicio;
}

#endif // LISTA_H

