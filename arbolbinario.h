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
       T Padre(T);
       void setPadre(Nodo<T> *);
       Nodo<T> *getPadre();
       bool estaVacio();
       void Insertar(T);
       void Preorden(Nodo<T> *);
       void Inorden(Nodo<T> *);
       void Posorden(Nodo<T> *);
       Nodo<T> *Buscar(T);
       Nodo<T> *Buscar2(Nodo<T> *, T);
       Nodo<T> *BuscarReemp(Nodo<T> *);
       Nodo<T> *Eliminar(T);
       int Grado(T);
       int Nivel(T);
       int Camino(T, T); //bool
       int Altura(Nodo<T> *);
       void MostrarxNiveles();
       void MostrarNivel(Nodo<T> *, int);
       int Isomorfos(Nodo<T> *, Nodo<T> *); //bool
       Nodo<T> *RD(Nodo<T> *);
       Nodo<T> *RI(Nodo<T> *);
       Nodo<T> *DRD(Nodo<T> *);
       Nodo<T> *DRI(Nodo<T> *);
       Nodo<T> *Balanceo(Nodo<T> *);
};
#endif // ARBOLBINARIO_H
