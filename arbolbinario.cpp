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
    return;
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
void ArbolBinario<T>::Insertar(T dato){
    Nodo<T> *nuevo = new Nodo<T>(dato);
    if(estaVacio()){
        raiz = nuevo;
    }
    else{
        Nodo<T> *ant = nullptr;
        Nodo<T> *act = raiz;
        while((act != nullptr) && (act->getInfo() != dato)){
            ant = act;
            if (act->getInfo() < dato){
        	    act = act->getDer();
            }
        	else{
                act = act->getIzq();
            }
        }
        if (act == nullptr)
               if (ant->getInfo() < dato){
                   ant->setDer(nuevo);
               }
               else{
                   ant->setIzq(nuevo);
               }
        else{
            cout<<" Dato ya existe ...."<<endl;
        }
    }
    return;
}

template <typename T>
void ArbolBinario<T>::Preorden(Nodo<T> *aux){
    //CASO BASE
    if(aux!=nullptr){
        cout<<aux->getInfo()<<"\t";
        Preorden(aux->getIzq());
        Preorden(aux->getDer());
    }
    return;
}

template <typename T>
void ArbolBinario<T>::Inorden(Nodo<T> *aux){
    //CASO BASE
    if(aux!=nullptr){
        Inorden(aux->getIzq());
        cout<<aux->getInfo()<<"\t";
        Inorden(aux->getDer());
    }
    return;
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
    return;
}

int x = 0;
template <typename T>
void ArbolBinario<T>::Imprimir(Nodo<T> *aux){
    if (aux == NULL){
            return;
    }
    cout <<" "<< aux->getInfo() << endl;
    ImpTree(aux, "");
    cout << endl;
}

template <typename T>
void ArbolBinario<T>::ImpTree(Nodo<T>* aux, const string& prefix){
    if (aux == NULL){
        return;
    }
    bool hasLeft = (aux->getIzq() != NULL);
    bool hasRight = (aux->getDer() != NULL);
    if (!hasLeft && !hasRight){
        return;
    }
    char m = 195, m3 = 196, m2 = 192, m1 = 179;
    cout << prefix;
    if(hasLeft  && hasRight){
            cout<<" "<<m<<m3<<m3<<"D"<<m3<<m3<<">";
    }
    else{
        cout<<"";
    }
    if(!hasLeft  && hasRight){
            cout<<" "<<m2<<m3<<m3<<"D"<<m3<<m3<<">";
    }
    else{
        cout<<"";
    }
    if (hasRight){
        bool printStrand = (hasLeft && hasRight && (aux->getDer()->getDer() != NULL || aux->getDer()->getIzq() != NULL));
        string newPrefix;
        if(printStrand){
            newPrefix = prefix + " " + m1 + "     ";
        }
        else{
            newPrefix = prefix + "       ";
        }
        cout << aux->getDer()->getInfo() << endl;
        ImpTree(aux->getDer(), newPrefix);
    }
    if (hasLeft){
        if(hasRight){
            cout<<prefix;
        }
        else{
            cout<<"";
        }
        cout<<" "<<m2<<m3<<m3<<"I"<<m3<<m3<<">"<<aux->getIzq()->getInfo() << endl;
        ImpTree(aux->getIzq(), prefix + "       ");
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
        case 1:
            if(aux->getIzq() != nullptr){
                return aux->getIzq();
            }
            else{
                return aux->getDer();
            }
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
int ArbolBinario<T>::Peso(Nodo<T> *actual){
	if (actual == NULL) return 0;
	else return 1 + Peso(actual->getDer()) + Peso(actual->getIzq());
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
    return;
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
    return;
}

template <typename T>
bool ArbolBinario<T>::Isomorfos(Nodo<T> *arb1, Nodo<T> *arb2){
    if((arb1 == nullptr)&&(arb2 == nullptr)){
        return true;
    }
    if(((arb1->getIzq() != nullptr)&&(arb2->getIzq() == nullptr)) || ((arb1->getIzq() == nullptr)&&(arb2->getIzq() != nullptr)) || ((arb1->getDer() != nullptr)&&(arb2->getDer() == nullptr)) || ((arb1->getDer() == nullptr)&&(arb2->getDer() != nullptr))){
        return false;
    }
    else{
        return true;
    }
}

template <typename T>
bool ArbolBinario<T>::Distintos(Nodo<T> *arb1, Nodo<T> *arb2){
    if(Peso(arb1) != Peso(arb2)){
        return true;
    }
    if(((arb1 != nullptr) && (arb2 == nullptr)) || ((arb1 == NULL) && (arb2 != NULL))){
        return true;
    }
    else{
        if(arb1->getInfo() != arb2->getInfo()){
            return true;
        }
        else{
            Distintos(arb1->getIzq(), arb2->getIzq());
            Distintos(arb1->getDer(), arb2->getDer());
        }
    }
    return false;
}

template <typename T>
bool ArbolBinario<T>::Semejantes(ArbolBinario<T> *arb1, ArbolBinario<T> *arb2){
    bool sem = false;
    if(Peso(arb1->getRaiz()) != Peso(arb2->getRaiz())){
        return false;
    }
    else{
        sem = arb1->CompSemejantes(arb1->getRaiz(), arb2);
        sem = arb2->CompSemejantes(arb2->getRaiz(), arb1);
        return sem;
    }
}

template <typename T>
Nodo<T>* ArbolBinario<T>::BuscarNodo(T dato){
    Nodo<T> *act = raiz;
    while((act != nullptr) && (act->getInfo() != dato)){
        if(act->getInfo() > dato){
            act = act->getIzq();
        }
        else{
            act =act->getDer();
        }
    }
    if(act != nullptr){
        return act;
    }
    else{
        return nullptr;
    }
}

template <typename T>
bool ArbolBinario<T>::CompSemejantes(Nodo<T> *arb1, Nodo<T> *arb2){
    if(arb1 != nullptr){
        if(arb2->BuscarNodo(arb1->getInfo()) == nullptr){
            return false;
        }
        else{
            return CompSemejantes(arb1->getIzq(), arb2) && CompSemejantes(arb1->getDer(), arb2);
        }
    }
    return true;
}

template <typename T>
bool ArbolBinario<T>::Iguales(ArbolBinario<T> *arb1, ArbolBinario<T> *arb2){
    if((Semejantes(arb1, arb2)) && (Isomorfos(arb1->getRaiz(), arb2->getRaiz()))){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
Nodo<T>* ArbolBinario<T>::RD(Nodo<T> *p){
    cout<<"\tRD -> \t"<<p->getInfo()<<endl;
    Nodo<T>* q = p->getIzq();
    p->setIzq(q->getDer());
    q->setDer(p);
    return q;
}

template <typename T>
Nodo<T>* ArbolBinario<T>::RI(Nodo<T>* p) {
    cout<<"\tRI -> \t"<<p->getInfo()<<endl;
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
        p->setIzq(Balanceo(p->getIzq()));
        p->setDer(Balanceo(p->getDer()));
        int dif = Altura(p->getIzq()) - Altura(p->getDer());
        if(abs(dif) > 1){
            if(dif > 0){
                Nodo<T>* q = p->getIzq();
                int difq = Altura(q->getIzq()) - Altura(q->getDer());
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
    return p;
}

template <typename T>
int ArbolBinario<T>::Equiponderados(Nodo<T> *aux){
    if(aux == nullptr){
        return 1;
    }
    int dif = Peso(aux->getIzq()) - Peso(aux->getDer());
    if(dif == 0){
        int n1 = Equiponderados(aux->getIzq());
        int n2 = Equiponderados(aux->getDer());
        if((n1 == 1) && (n2 == 1)){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

template <typename T>
void ArbolBinario<T>::MultDatos(Nodo<T> *aux){
    if((aux->getDer() != nullptr) && (aux->getIzq() != nullptr)){
        aux->setInfo(aux->getIzq()->getInfo() * aux->getDer()->getInfo());
    }
    if(aux->getIzq() != nullptr){
        aux->MultDatos(aux->getIzq());
    }
    if(aux->getDer() != nullptr){
        aux->MultDatos(aux->getDer());
    }
    return;
}

template <typename T>
int ArbolBinario<T>::cantidadNodosArbol(Nodo<T> *actual){
     if (actual == NULL) return 0;
     else return 1 + cantidadNodosArbol(actual->getDer()) + cantidadNodosArbol(actual->getIzq());
}
