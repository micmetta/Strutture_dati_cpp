* lista.h
 *
 *  Created on: 24 gen 2018
 *      Author: miky9
 */

#ifndef LISTE_H_
#define LISTE_H_
#include <iostream>
#include <stdlib.h>
#include "cella_lista.h"
#include "liste.h"

using namespace std;


template <class T>

class Lista_circ {


 public:

   Lista_circ();
   Lista_circ(Lista_circ<T>&);//costruttore di copia
   ~Lista_circ();

   //operatori
   typedef Cella_lista<T>* posizione;//posizione da ora sarà un nuovo tipo di puntatore alla Cella della lista

   //void crea_lista();
   bool lista_vuota();
   T leggi_elemento(posizione);
   void scrivi_nodo(T,posizione);
   posizione leggi_primolista();
   bool verifica_finelista(posizione);//restituisce true se la cella passata in input è la cella fittizia a cui punta L (L = lista)
   bool verifica_ultimo_elemento(posizione);//restitusice true se la cella passata in input è l'ultimo della lista altrimenti restituisce false
   posizione leggi_succ(posizione);//restituisce la cella successiva rispetto a quella passata in input
   posizione leggi_prec(posizione);//restituisce la cella precedente rispetto a quella passata in input
   int get_num_elementi();

   //crea una nuova cella con il valore passato come primo parametro e la inserisce come precedente alla
   //cella passata come secondo parametro. La cella che precedeva il secondo parametro diventa precedente
   //alla nuova cella che viene creata, e la cella successiva a quella creata diventa la cella passata come
   //secondo parametro.
   void inserisci_nodo(T, posizione);


   //cancella la cella passata in input. La cella precedente alla cella passata in input punterà
   //alla cella successiva di quella passata in input. Il puntatore precedente della cella successiva a quella
   //passata in input punterà alla cella che precede quella da cancellare.
   //Dopodichè si dealloca lo spazio della cella da cancellare.
   void cancella_cella(posizione);



   void stampa_lista();

   //sovraccarico l'operatore di uguaglianza
   Lista_circ <T>& operator=(Lista_circ <T>& ref) {

     posizione p;

     p = ref.leggi_primolista();


       while(!ref.verifica_ultimo_elemento(p)){

             p = ref.leggi_succ(p);


       }

       //p ora è proprio l'ultimo elemento della lista da copiare
       while(!ref.verifica_finelista(p)){

    	   this->inserisci_nodo(p->leggi_elemento(), leggi_primolista());
           p = ref.leggi_prec(p);

       }

    return *this;

   }



 private:

//la lista è un puntatore ad un oggetto di tipo cella
posizione lista;
int num_elementi;
};




template <class T>
Lista_circ<T>::Lista_circ()
{

     //crea_lista();
//la lista punta sempre ad una cella fittizia (di controllo) che avrà sempre il puntatore succ al primo elemento della lista(se c'è).
//Se la lista non contiene elementi i puntatori della cella "di controllo" avranno sempre
//il puntatore succ e prec che punteranno a se stessa proprio come avviene nel costruttore qui sotto.

lista = new Cella_lista<T>;
lista->inserisci_cella_prec(lista);
lista->inserisci_cella_succ(lista);
num_elementi = 0;

//elemento conterrà un valore casuale
}


/*
template <class T>
void Lista_circ<T>::crea_lista(){

	lista = new Cella_lista<T>;
	lista->inserisci_cella_prec(lista);
	lista->inserisci_cella_succ(lista);
	num_elementi = 0;
	//elemento conterrà un valore casuale


}
*/





template <class T>
Lista_circ<T>::~Lista_circ()
{
	while(lista->leggi_cella_prec() != lista->leggi_cella_succ()){

		cancella_cella(lista->leggi_cella_succ());

	}


	delete lista;


}






template <class T>
bool Lista_circ<T>::lista_vuota()
{
	return (lista->leggi_cella_prec() == lista && lista->leggi_cella_succ() == lista);

}






template <class T>
typename Lista_circ<T>::posizione Lista_circ<T>::leggi_primolista()
{

return lista->leggi_cella_succ();

}



template<class T>
typename Lista_circ<T>::posizione Lista_circ<T>::leggi_succ(posizione ref)
{
	return ref->leggi_cella_succ();

}




template<class T>
typename Lista_circ<T>::posizione Lista_circ<T>::leggi_prec(posizione ref)
{
	return ref->leggi_cella_prec();

}






template <class T>
bool Lista_circ<T>::verifica_finelista(posizione ref)
{
return (ref == lista);
}



template <class T>
T Lista_circ<T>::leggi_elemento(posizione ref)
{
return ref->leggi_elemento();
}






template <class T>
bool Lista_circ<T>::verifica_ultimo_elemento(posizione ref)
{
	return (ref->leggi_cella_succ() == lista);
}








template <class T>
void Lista_circ<T>::scrivi_nodo(T valore, posizione ref)
{
ref->inserisci_elemento(valore);
}




template <class T>
void Lista_circ<T>::inserisci_nodo(T valore, posizione ref)
{
//creo una nuova cella e inserisco al suo interno il valore passato in input
posizione temp = new Cella_lista <T>;
temp->inserisci_elemento(valore);


//la cella che precede ref diventa precedente a temp
// e la cella successiva a temp diventa ref
temp->inserisci_cella_prec(ref->leggi_cella_prec());
temp->inserisci_cella_succ(ref);


//la cella che ora precede temp deve puntare come cella successiva a temp
//e ref come cella precedente dovrà puntare a temp

ref->leggi_cella_prec()->inserisci_cella_succ(temp);
ref->inserisci_cella_prec(temp);

ref = temp;

num_elementi++;
}










template <class T>
void Lista_circ<T>::cancella_cella(posizione ref)
{

posizione temp;

temp = ref;

//colleghiamo la cella che precede ref alla cella successiva di ref
ref->leggi_cella_prec()->inserisci_cella_succ(ref->leggi_cella_succ());

//colleghiamo il precedente della cella successiva a ref alla cella che precede ref
ref->leggi_cella_succ()->inserisci_cella_prec(ref->leggi_cella_prec());

ref = ref->leggi_cella_succ();
delete (temp);
}



//Se la lista è vuota non mi stampa nulla perchè nel while non entra
template <class T>
void Lista_circ<T>::stampa_lista()
{
	Cella_lista <T>* temp;

    temp = leggi_primolista();

    while(!verifica_finelista(temp)){//controlla se temp è la cella fittizia perchè se così fosse
    	                             //significa che la lista è vuota quindi non deve stampare nulla
     	cout << temp->leggi_elemento << endl;

    	temp = leggi_succ(temp);

     }


}













template <class T>
int Lista_circ<T>::get_num_elementi()
{
	return num_elementi;
}




#endif /* LISTE_H_ */
