#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "nodo.h"

template <class T>
class ArbolBinario{

    private:
        Nodo<T> *raiz;
        Nodo<T> *padre;

    public:
        ArbolBinario();
       ~ArbolBinario();
       void DestruirArbol(Nodo<T> *);
       void setRaiz(Nodo<T> *);
       Nodo<T> *getRaiz();
       void setPadre(Nodo<T> *);
       Nodo<T> *getPadre();
       bool estaVacio();
       void Insertar(T);
       void Preorden(Nodo<T> *); // RECORRER  EL
       void Inorden(Nodo<T> *); //  ARBOL
       void Posorden(Nodo<T> *); //  INCLUYE MOSTRAR
       //CONTAR EL NIVEL Y LA ALTURA DEL ARBOL
       Nodo<T> *Buscar(T);
       bool BuscarB(T);
       void Eliminar(T);
       int Nivel(T, int);
       bool Camino(T, T);
};

#endif // ARBOLBINARIO_H
