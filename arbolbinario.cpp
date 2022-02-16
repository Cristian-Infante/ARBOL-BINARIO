#include "arbolbinario.h"

template <typename T>
ArbolBinario<T>::ArbolBinario(){
    raiz = nullptr;
}

template <typename T>
ArbolBinario<T>::~ArbolBinario(){
    DestruirArbol(getRaiz());
}

template <typename T>
void ArbolBinario<T>::DestruirArbol(Nodo<T> *aux){
    //CASO BASE
    if(aux!=nullptr){
        DestruirArbol(aux->getIzq());
        DestruirArbol(aux->getDer());
        aux->~Nodo();
    }
    if(aux == raiz){
        setRaiz(NULL);
    }
}

template <typename T>
void ArbolBinario<T>::setRaiz(Nodo<T> *nuevo){
    raiz = nuevo;
}

template <typename T>
Nodo<T>* ArbolBinario<T>::getRaiz(){
    return raiz;
}

template <typename T>
bool ArbolBinario<T>::estaVacio(){
    return(raiz==nullptr);
}
template <typename T>
void ArbolBinario<T>::setPadre(Nodo<T> *nuevo){
    padre = nuevo;
}

template <typename T>
Nodo<T>* ArbolBinario<T>::getPadre(){
    return padre;
}

template <typename T>
void ArbolBinario<T>::Insertar(T dato){
    Nodo<T> *nuevo = new Nodo<T>(dato);
    Nodo<T> *padreT = getPadre();

    //Nodo<T> *actual = raiz;
   //Nodo<T> *padre = nullptr;

    if(estaVacio()){
        //raiz = nuevo;
        setRaiz(nuevo);
        setPadre(nuevo);
         //this->setRaiz(nuevo);
    }

    //SI EL DATO ES MAYOR QUE EL PADRE
    else if(padreT->getInfo()<dato){
       //CASO BASE
        if(padreT->getDer()==nullptr){
            padreT->setDer(nuevo);
            setPadre(getRaiz());
        }
        else{
            setPadre(padreT->getDer());
            Insertar(dato);

        }
    }
    //SI EL DATO ES MENOR QUE EL PADRE
    else if(padreT->getInfo()>dato){
      //CASO BASE
        if(padreT->getIzq()==nullptr){
            padreT->setIzq(nuevo);
            setPadre(getRaiz());
        }
        else{
            setPadre(padreT->getIzq());
            Insertar(dato);
        }
    }

}

template <typename T>
void ArbolBinario<T>::Preorden(Nodo<T> *aux){
    //CASO BASE
    if(aux!=nullptr){
        cout<<aux->getInfo()<<"\t";
        Preorden(aux->getIzq());
        Preorden(aux->getDer());
    }
}

template <typename T>
void ArbolBinario<T>::Inorden(Nodo<T> *aux){
    //CASO BASE
    if(aux!=nullptr){
        Inorden(aux->getIzq());
        cout<<aux->getInfo()<<"\t";
        Inorden(aux->getDer());
    }
}

template <typename T>
void ArbolBinario<T>::Posorden(Nodo<T> *aux){
    //CASO BASE
    if(aux!=nullptr){
        Posorden(aux->getIzq());
        Posorden(aux->getDer());
        cout<<aux->getInfo()<<"\t";
    }
    else if(estaVacio()){
        cout<<endl<<"Is Empty";
    }
}

template <typename T>
Nodo<T> *ArbolBinario<T>::Buscar(T dato){
    Nodo<T> *padreT = getPadre();
    if (estaVacio()){
        return 0;
    }
    if(padreT->getInfo()<dato){
        setPadre(padreT->getDer());
        Buscar(dato);
    }
    else if(padreT->getInfo()>dato){
        setPadre(padreT->getDer());
        Buscar(dato);
    }
    else {
        return  padreT;
    }
}

template <typename T>
bool ArbolBinario<T>::BuscarB(T dato){
    Nodo<T> *padreT = getPadre();
    if (estaVacio()){
        return false;
    }
    if((padre->getInfo()!=NULL)&&(padre->getInfo()!=dato)){
        if(padreT->getInfo()<dato){
            setPadre(padreT->getDer());
            Buscar(dato);
        }
        else if(padreT->getInfo()>dato){
            setPadre(padreT->getDer());
            Buscar(dato);
        }
    }
    if(padre->getInfo()==dato){
        return true;
    }
}

template <typename T>
int ArbolBinario<T>::Nivel(T dato, int nivel){
    Nodo<T> *padreT = getPadre();
    if(padreT->getInfo()<dato){
        setPadre(padreT->getDer());
        nivel++;
        Nivel(dato, nivel);
    }
    else if(padreT->getInfo()>dato){
        setPadre(padreT->getDer());
        nivel++;
        Nivel(dato, nivel);
    }
    else {
        return  nivel;
    }
}
