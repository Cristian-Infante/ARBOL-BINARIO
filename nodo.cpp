#include "nodo.h"

template <typename T>
Nodo<T>::Nodo(T dato){
    info = dato;
    izq = nullptr;
    der = nullptr;
}

template <typename T>
Nodo<T>::~Nodo(){
    info = NULL;
    izq = NULL;
    der = NULL;
}

template <typename T>
void Nodo<T>::setInfo(T dato){
    info = dato;
}

template <typename T>
T Nodo<T>::getInfo(){
    return info;
}

template <typename T>
void Nodo<T>::setIzq(Nodo *nuevo){
    izq = nuevo;
}

template <typename T>
Nodo<T>* Nodo<T>::getIzq(){
    return izq;
}

template <typename T>
void Nodo<T>::setDer(Nodo<T> *nuevo){
    der = nuevo;
}

template <typename T>
Nodo<T>* Nodo<T>::getDer(){
    return der;
}

template <typename T>
void Nodo<T>::mostrarNodo(){
    cout<<info<<endl;
}
