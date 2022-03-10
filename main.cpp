#include "arbolbinario.h"
#include "arbolbinario.cpp"
#include "nodo.h"
#include "nodo.cpp"

ArbolBinario<int> *a = new ArbolBinario<int>();

int main(){
    cout<<endl;
    a->Insertar(6);
    a->Insertar(3);
    a->Insertar(8);
    a->Insertar(12);
    a->Insertar(1);
    a->Insertar(7);
    a->Insertar(15);
    a->Insertar(20);
    cout<<"CAMINO 6-1: "<<a->Camino(6, 1)<<endl<<endl;

    cout<<"PESO "<<a->getRaiz()->getDer()->getInfo()<<": "<<a->Peso(a->getRaiz()->getDer())<<endl<<endl;

    cout<<"NIVEl 15: "<<a->Nivel(15)<<endl;
    cout<<"NIVEl 16: "<<a->Nivel(16)<<endl;

    cout<<"ALTURA: "<<a->Altura(a->getRaiz())<<endl<<endl;

    cout<<"PADRE: "<<a->Padre(12)<<endl<<endl;

    cout<<"SEARCH: "<<a->Buscar(15)->getInfo()<<endl<<endl;

    cout<<"PRE-ORDEN:\t"; a->Preorden(a->getRaiz()); cout<<endl;
    cout<<"IN-ORDEN:\t"; a->Inorden(a->getRaiz()); cout<<endl;
    cout<<"POST-ORDEN:\t"; a->Posorden(a->getRaiz()); cout<<endl<<endl;

    cout<<"MOSTAR X NIVELES: "; a->MostrarxNiveles(); cout<<endl<<endl;

    a->Balanceo(a->getRaiz());
    cout<<"MOSTAR X NIVELES DESPUES DE BALANCEO: "; a->MostrarxNiveles(); cout<<endl<<endl;

    a->~ArbolBinario();
    //a->DestruirArbol(a->getRaiz());
    cout<<"POST-ORDEN:\t"; a->Posorden(a->getRaiz()); cout<<endl<<endl;

    a->Insertar(1);
    a->Insertar(2);
    cout<<"PRE-ORDEN: "; a->Preorden(a->getRaiz()); cout<<endl<<endl;

    return 0;
}
