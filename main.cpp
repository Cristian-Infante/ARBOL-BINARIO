#include "arbolbinario.h"
#include "arbolbinario.cpp"
#include "nodo.h"
#include "nodo.cpp"

ArbolBinario<int> *a = new ArbolBinario<int>();

int nivel(int dato){
    if(!a->estaVacio()){
        if(a->BuscarB(dato)){
            int x = a->Nivel(dato,1);
            if(x == 0){
                cout<<"No existe"<<endl;
            }
            else{
                cout<<"Nivel: "<<x-1<<endl;
            }
        }
    }
    else{
        cout<<"is Empty"<<endl;
    }
}

int main(){
    cout << "Hello world!" << endl;
    a->Insertar(6);
    a->Insertar(3);
    a->Insertar(8);
    a->Insertar(12);
    a->Insertar(1);
    a->Insertar(7);
    a->Insertar(15);
    nivel(15);
    //nivel(16);
    a->Preorden(a->getRaiz());
    //a->Inorden(a->getRaiz());
    a->~ArbolBinario();
    cout<<endl;
    nivel(16);
    //a->DestruirArbol(a->getRaiz());
    cout<<endl;
    a->Posorden(a->getRaiz());
    a->Insertar(1);
    a->Insertar(2);
    a->Preorden(a->getRaiz());

    return 0;
}
