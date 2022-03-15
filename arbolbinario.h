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
       bool estaVacio();
       void Insertar(T);
       void Preorden(Nodo<T> *);
       void Inorden(Nodo<T> *);
       void Posorden(Nodo<T> *);

       void Imprimir(Nodo<T> *);
       void ImpTree(Nodo<T> *, const string&);

       Nodo<T> *Buscar(T);
       Nodo<T> *Buscar2(Nodo<T> *, T);
       Nodo<T> *BuscarReemp(Nodo<T> *);
       Nodo<T> *Eliminar(T);
       int Peso(Nodo<T> *);
       int Grado(T);
       int Nivel(T);
       int Camino(T, T); //bool
       int Altura(Nodo<T> *);
       void MostrarxNiveles();
       void MostrarNivel(Nodo<T> *, int);
       bool Isomorfos(Nodo<T> *, Nodo<T> *); //bool
       bool Distintos(Nodo<T> *, Nodo<T> *); //bool
       bool Semejantes(ArbolBinario<T> *, ArbolBinario<T> *); //bool
       bool Iguales(ArbolBinario<T> *, ArbolBinario<T> *); //bool
       Nodo<T> *BuscarNodo(T);
       bool CompSemejantes(Nodo<T> *, Nodo<T> *); //bool
       bool Iguales(Nodo<T> *, Nodo<T> *); //bool
       Nodo<T> *RD(Nodo<T> *);
       Nodo<T> *RI(Nodo<T> *);
       Nodo<T> *DRD(Nodo<T> *);
       Nodo<T> *DRI(Nodo<T> *);
       Nodo<T> *Balanceo(Nodo<T> *);
       int Equiponderados(Nodo<T> *); //bool
       void MultDatos(Nodo<T> *);
       int cantidadNodosArbol(Nodo<T> *actual);
};
#endif // ARBOLBINARIO_H
