
#ifndef CELLA_ALBERI_N_ARI_H_
#define CELLA_ALBERI_N_ARI_H_
#include "cella_alberi_n-ari.h"
#include <stdlib.h>

template <class T>
class Cella_n_ari
{

public:


	Cella_n_ari();
	Cella_n_ari(T);

    void inserisci_valore(T); //inserisce in elemento il valore di tipo T passato in input.
    T getValore(); //permette di recuperare il valore di elemento.
	void inserisci_primo_figlio(Cella_n_ari <T>*);//inserisce un primofiglio (nodo di input) al nodo corrente.
    void inserisci_fratello(Cella_n_ari <T>*);//inserisce un fratello (nodo di input) al nodo corrente
    void inserisci_padre(Cella_n_ari <T>*);//inserisce al nodo corrente il padre (nodo di input)


    Cella_n_ari <T>* leggi_primofiglio() const;//restituisce il primofiglio del nodo corrente
    Cella_n_ari <T>* leggi_fratello() const;//restituisce il fratello del nodo corrente
    Cella_n_ari <T>* leggi_padre() const;//restituisce il padre del nodo corrente


    bool operator==(Cella_n_ari <T>*);
    bool operator<=(Cella_n_ari <T>*);



private:
    T elemento;
    Cella_n_ari <T>* primo_figlio;
    Cella_n_ari <T>* fratello;
    Cella_n_ari <T>* padre;

};


//Implementazione della classe

template <class T>
Cella_n_ari<T>::Cella_n_ari()
{

primo_figlio = NULL;
fratello = NULL;
padre = NULL;

}



template <class T>
Cella_n_ari<T>::Cella_n_ari(T valore)
{
primo_figlio = NULL;
fratello = NULL;
padre = NULL;

elemento = valore;

}




template <class T>
void Cella_n_ari<T>::inserisci_valore(T valore)
{

elemento = valore;

}


template <class T>
T Cella_n_ari<T>::getValore()
{

return elemento;

}




template <class T>
void Cella_n_ari<T>::inserisci_primo_figlio(Cella_n_ari<T>* ref)
{
primo_figlio = ref;
}




template <class T>
void Cella_n_ari<T>::inserisci_fratello(Cella_n_ari<T>* ref)
{
fratello = ref;
}



template <class T>
void Cella_n_ari<T>::inserisci_padre(Cella_n_ari<T>* ref)
{
padre = ref;
}





template <class T>
Cella_n_ari <T>* Cella_n_ari<T>::leggi_primofiglio() const
{

return primo_figlio;

}




template <class T>
Cella_n_ari <T>* Cella_n_ari<T>::leggi_fratello() const
{

return fratello;

}





template <class T>
Cella_n_ari <T>* Cella_n_ari<T>::leggi_padre() const
{

return padre;

}





//sovraccaricamento degli operatori <= e ==

template <class T>
bool Cella_n_ari<T>::operator==(Cella_n_ari <T>* ref)

{

return (getValore() == ref->getValore());

}



template <class T>
bool Cella_n_ari<T>::operator<=(Cella_n_ari <T>* ref)
{

return (getValore <= ref->getValore());
}




#endif /* CELLA_ALBERI_N_ARI_H_ */
