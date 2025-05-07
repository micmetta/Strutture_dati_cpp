* cella_lista.h
 *
 *  Created on: 24 gen 2018
 *      Author: miky9
 */

#ifndef CELLA_LISTA_H_
#define CELLA_LISTA_H_
#include <iostream>
#include <stdlib.h>
#include "cella_lista.h"


//La cella presenta due puntatori uno al precedente e un altro al successivo perchè
//l'implementazione scelta è quella della lista circolare mediante puntatori



template <class T>

class Cella_lista {

    public:

	Cella_lista();
	Cella_lista(T valore);
	void inserisci_elemento(T);//inserisce il valore di tipo T passato in input nella variabile privata elemento
	T leggi_elemento();//restituisce il valore dell'elemento
	void inserisci_cella_succ(Cella_lista<T>*);//fa puntare il puntatore della cella corrente succ alla cella passata in input
	Cella_lista<T>* leggi_cella_succ();//restituisce la cella che è successiva rispetto a quella corrente
	void inserisci_cella_prec(Cella_lista<T>*);//fa puntare il puntatore della cella corrente prec alla cella passata in input
	Cella_lista<T>* leggi_cella_prec();//restituisce la cella che precede quella corrente
	bool operator==(Cella_lista<T>);



    private:

	T elemento;
	Cella_lista<T> *prec;//puntatore alla cella successiva
	Cella_lista<T> *succ;//puntatore alla cella precedente

};



template <class T>
Cella_lista<T>::Cella_lista()
{
	prec = NULL;
	succ = NULL;

}




template <class T>
Cella_lista<T>::Cella_lista(T valore)
{
	prec = NULL;
	succ = NULL;
	elemento = valore;
}



template <class T>
void Cella_lista<T>::inserisci_elemento(T valore)
{
	elemento = valore;
}



template <class T>
T Cella_lista<T>::leggi_elemento()
{
	return elemento;
}




template <class T>
void Cella_lista<T>::inserisci_cella_prec(Cella_lista<T>* ref)
{
	prec = ref;

}



template <class T>
void Cella_lista<T>::inserisci_cella_succ(Cella_lista<T>* ref)
{
	succ = ref;

}



template <class T>
Cella_lista<T>* Cella_lista<T>::leggi_cella_prec()
{
	return prec;

}




template <class T>
Cella_lista<T>* Cella_lista<T>::leggi_cella_succ()
{
	return succ;

}


//sovraccaricamento dell'operatore ==
template <class T>
bool Cella_lista<T>::operator ==(Cella_lista<T> ref)
{
return (leggi_elemento() == ref.leggi_elemento());

}








#endif /* CELLA_LISTA_H_ */
