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
T ArbolBinario<T>::Padre(T dato){
    Nodo<T> *ant = nullptr;
    Nodo<T> *act = raiz;
    while((act != nullptr)&&(act->getInfo() != dato)){
        ant = act;
        if(act->getInfo() > dato){
            act = act->getIzq();
        }
        else{
            act = act->getDer();
        }
    }
    if(act != nullptr){
        return ant->getInfo();
    }
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
    Nodo<T> *aux = raiz;
    while((aux != nullptr)&&(aux->getInfo() != dato)){
        if(aux->getInfo() > dato){
            aux = aux->getIzq();
        }
        else{
            aux = aux->getDer();
        }
    }
    return aux;
}

template <typename T>
Nodo<T> *ArbolBinario<T>::Buscar2(Nodo<T> *aux, T dato){
    if((aux != nullptr)&&(aux->getInfo() != dato)){
        if(aux->getInfo() > dato){
            return Buscar2(aux->getIzq(),dato);
        }
        if(aux->getInfo() < dato){
            return Buscar2(aux->getDer(),dato);
        }
    }
}

template <typename T>
Nodo<T>* ArbolBinario<T>::BuscarReemp(Nodo<T> *aux){
    switch(Grado(aux->getInfo())){
        case 0:
            return nullptr;
            break;
        case 1:
            if(aux->getIzq() != nullptr){
                return aux->getIzq();
            }
            else{
                return aux->getDer();
            }
            break;
        case 2:
            Nodo<T> *ant = nullptr;
            Nodo<T> *act = aux->getIzq();
            while(act->getDer() != nullptr){
                ant = act;
                act = act->getDer();
            }
            if(ant != nullptr){
                ant->setDer(act->getIzq());
                act->setIzq(aux->getIzq());
            }
            act->setDer(aux->getDer());
            return act;
    }
}

template <typename T>
Nodo<T>* ArbolBinario<T>::Eliminar(T dato){
    Nodo<T> *padre = nullptr;
    Nodo<T> *salir = raiz;
    while((salir != nullptr)&&(salir->getInfo() != dato)){
        padre = salir;
        if(salir->getInfo() > dato){
            salir = salir->getIzq();
        }
        else{
            salir = salir->getDer();
        }
    }
    if(salir != nullptr){
        Nodo<T> *reemp = BuscarReemp(salir);
        if(padre != nullptr){
            if(padre->getInfo() > dato){
                padre->setIzq(reemp);
            }
            else{
                padre->setDer(reemp);
            }
        }
        else{
            raiz = reemp;
        }
    }
}

template <typename T>
int ArbolBinario<T>::Grado(T dato){
    Nodo<T> *aux = Buscar(dato);
    if(aux != nullptr){
        int cont = 0;
        if(aux->getIzq() != nullptr){
            cont++;
        }
        if(aux->getDer() != nullptr){
            cont++;
        }
        return cont;
    }
    return -1;
}

template <typename T>
int ArbolBinario<T>::Nivel(T dato){
    Nodo<T> *aux = raiz;
    int cont = 0;
    while((aux != nullptr)&&(aux->getInfo() != dato)){
        cont++;
        if(aux->getInfo() > dato){
            aux = aux->getIzq();
        }
        else{
            aux = aux->getDer();
        }
    }
    if(aux != nullptr){
        return cont;
    }
    else {
        return  -1;
    }
}

template <typename T>
int ArbolBinario<T>::Camino(T dato1, T dato2){
    Nodo<T> *valor1 = Buscar(dato1);
    if(valor1 != nullptr){
        Nodo<T> *valor2 = Buscar2(valor1, dato2);
        if(valor2 != nullptr){
            return 1;
        }
        else{
            return 0;
        }
    }
}

template <typename T>
int ArbolBinario<T>::Altura(Nodo<T> *aux){
    int altIZ, altDE;
    if(aux != nullptr){
        altIZ = Altura(aux->getIzq());
        altDE = Altura(aux->getDer());
        if(altIZ > altDE){
            return altIZ+1;
        }
        else{
            return altDE+1;
        }
    }
    else{
        return 0;
    }
}

template <typename T>
void ArbolBinario<T>::MostrarxNiveles(){
    Nodo<T> *aux = raiz;
    int alt = Altura(aux);
    for(int i=0; i<alt; i++){
        cout<<endl<<"\tNivel "<<i<<":\t";
        MostrarNivel(aux, i);
    }
}

template <typename T>
void ArbolBinario<T>::MostrarNivel(Nodo<T> * aux, int nivel){
    if((aux != nullptr)&&(nivel !=0)){
        MostrarNivel(aux->getIzq(), nivel-1);
        MostrarNivel(aux->getDer(), nivel-1);
    }
    else{
        if(aux != nullptr){
            cout<<aux->getInfo()<<"\t";
        }
    }
}

template <typename T>
int ArbolBinario<T>::Isomorfos(Nodo<T> *arb1, Nodo<T> *arb2){
    if((arb1 == nullptr)&&(arb2 == nullptr)){
        return 1;
    }
    if(((arb1->getIzq() != nullptr)&&(arb2->getIzq() == nullptr)) || ((arb1->getIzq() == nullptr)&&(arb2->getIzq() != nullptr)) || ((arb1->getDer() != nullptr)&&(arb2->getDer() == nullptr)) || ((arb1->getDer() == nullptr)&&(arb2->getDer() != nullptr))){
        return 0;
    }
    else{
        return 1;
    }
}

template <typename T>
Nodo<T>* ArbolBinario<T>::RD(Nodo<T> *p){
    Nodo<T>* q = p->getIzq();
    p->setIzq(q->getDer());
    q->setDer(p);
    return q;
}

template <typename T>
Nodo<T>* ArbolBinario<T>::RI(Nodo<T>* p) {
    Nodo<T>* q = p->getDer();
    p->setDer(q->getIzq());
    q->setIzq(p);
    return q;
}

template <typename T>
Nodo<T>* ArbolBinario<T>::DRD(Nodo<T>* p) {
    Nodo<T>* q = p->getIzq();
    p->setIzq(RI(q));
    return RD(p);
}

template <typename T>
Nodo<T>* ArbolBinario<T>::DRI(Nodo<T>* p) {
    Nodo<T>* q = p->getDer();
    p->setDer(RD(q));
    return RI(p);
}

template <typename T>
Nodo<T>* ArbolBinario<T>::Balanceo(Nodo<T> *p){
    if(p != nullptr){
        /**/Preorden(p); cout<<endl;
        p->setIzq(Balanceo(p->getIzq()));
        p->setDer(Balanceo(p->getDer()));
        int dif = Altura(p->getIzq()) - Altura(p->getDer());
        //cout<<"\tDiferencia\t"<<Altura(p->getIzq()) - Altura(p->getDer())<<endl<<endl;
        if(abs(dif) > 1){
            /**/cout<<"entro";
            if(dif > 0){
                Nodo<T>* q = p->getIzq();
                int difq = Altura(q->getIzq()) - Altura(q->getIzq());
                if(difq >= 0){
                    return RD(p);
                }
                else{
                    return DRD(p);
                }
            }
            else{
                Nodo<T>* q = p->getDer();
                int difq = Altura(q->getIzq()) - Altura(q->getDer());
                if (difq < 0) {
                    return RI(p);
                }
                else {
                    return DRI(p);
                }
            }
        }
    }
}
