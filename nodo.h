#ifndef NODO_H
#define NODO_H
#include "string"
#include "iostream"
using namespace std;

template <class T>
class Nodo{
private:
    T info;
    Nodo *izq;
    Nodo *der;
    public:
        Nodo(T);
       ~Nodo();
       void setInfo(T);
       T getInfo();
       void setIzq(Nodo *);
       Nodo *getIzq();
       void setDer(Nodo *);
       Nodo *getDer();
       void mostrarNodo();
};

#endif // NODO_H
