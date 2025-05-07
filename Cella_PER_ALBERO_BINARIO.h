

#ifndef CELLA_H_
#define CELLA_H_
#include "cella.h"



//CREARE NEL MAIN SEMPRE LA RADICE NEW CELLA



template <class T>

//Cella è la classe del nodo di un albero binario
class Cella {


public:

//typedef T tipoelem;

Cella();
Cella(T);

void inserisci_valore(T);
T getValore();


void inserisci_figlio_sx(Cella<T>*);
void inserisci_figlio_dx(Cella<T>*);
void inserisci_padre(Cella<T>*);
Cella<T>* leggi_figlio_sx() const;
Cella<T>* leggi_figlio_dx() const;
Cella<T>* leggi_padre() const;
bool operator ==(Cella<T>);
bool operator <=(Cella<T>);





private:
T elemento;
Cella<T>* figlio_sx;
Cella<T>* figlio_dx;
Cella<T>* padre;


};



template <class T>
Cella<T>::Cella() {

figlio_sx = NULL;
figlio_dx = NULL;
padre = NULL;
}



template <class T>
Cella<T>::Cella(T e){
elemento = e;
figlio_sx = NULL;
figlio_dx = NULL;
padre = NULL;
}




template <class T>
void Cella <T>::inserisci_valore(T label){

elemento = label;
}


template <class T>
T Cella<T>:: getValore()

{

return elemento;

}


template <class T>
void Cella <T>::inserisci_figlio_sx(Cella<T>* p){

	figlio_sx = p;
}


template <class T>

void Cella<T> :: inserisci_figlio_dx(Cella<T>* p){

	figlio_dx = p;

}


template <class T>
void Cella <T> :: inserisci_padre(Cella <T> *p){

    padre = p;

}


//Un nodo è formato solo dalla radice, da un figlio sinistro e da un figlio destro.
template <class T>
Cella<T>* Cella <T> :: leggi_figlio_sx() const {

return figlio_sx;



}


template <class T>
Cella<T>* Cella<T> :: leggi_figlio_dx() const
{

return figlio_dx;

}


template <class T>

Cella<T>* Cella<T>::leggi_padre() const {

return padre;

}


template <class T>

bool Cella<T>::operator ==(Cella <T> cella){

return (getValore == cella.getValore);



}







template <class T>

bool Cella <T> :: operator <= (Cella <T> cella){

return (getValore <= cella.getValore);


}





#endif /* CELLA_H_ */
