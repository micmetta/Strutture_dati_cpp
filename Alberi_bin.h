
#ifndef ALBERI_BIN_H_
#define ALBERI_BIN_H_


#include <iostream>
#include "cella.h"
#include <stdlib.h>
#include "code.h"
#include "alberi_bin.h"


using namespace std;


template <class T>

class Albero_bin {


public:

//tipi
typedef Cella<T> *nodo;//per semplificare il codice assumo che nodo è di tipo Cella.
//costruttori e distruttori
Albero_bin();//costruttore dell'albero che inizializza la radice a NULL
~Albero_bin();
//operatori
//void crea_albero_bin();
bool albero_vuoto();
nodo leggi_radice();//restituisce il nodo radice
nodo leggi_padre(nodo);//restituisce il nodo padre del nodo passato in input
nodo leggi_figlio_sx(nodo);//restituisce il nodo che è figlio sinistro del nodo passato in input(se esiste)
nodo leggi_figlio_dx(nodo);//restitusice il nodo che è figlio destro del nodo passato in input(se esiste)
bool sinistro_vuoto(nodo);//restituisce true se il nodo passato in input non ha un figlio sinistro
bool destro_vuoto(nodo);//restituisce true se il nodo passato in input non ha un figlio destro
void costr_albero_bin();//metodo che costruisce automaticamente un albero binario
void canc_sottoalbero_bin(nodo);//metodo che effettua la cancellazione del sottoalbero che ha come radice il nodo passato in input
T leggi_nodo(nodo);//restituisce il valore del nodo passato in input
void scrivinodo(nodo, T);//inserisce nel valore del nodo di input l'elemento passato in input come secondo parametro
void ins_bin_radice(nodo);//inserisce all'albero la radice che corrisponderà al nodo passato in input
void ins_figlio_sx(nodo);//crea un figlio sinistro per il nodo passato in input
void ins_figlio_dx(nodo);//crea un figlio destro per il nodo passato in input
void cancella_albero();
void visita_in_ampiezza();
void visita_in_pre_ordine(nodo);
void visita_in_post_ordine(nodo);


private:

nodo radice;
int num_nodi;

};


template <class T>
Albero_bin <T>::Albero_bin(){

num_nodi = 0;
radice = NULL;

}





template <class T>
Albero_bin <T>:: ~Albero_bin() {

//Albero_bin <T> :: canc_sottoalbero_bin(radice);



}





template <class T>
void Albero_bin <T>::canc_sottoalbero_bin(nodo ref) {

nodo temp;// temp è il nodo padre
nodo iniziale;
iniziale = ref;

if(ref != NULL) {

   if(!sinistro_vuoto(ref)){


    canc_sottoalbero_bin(leggi_figlio_sx(ref));

   }


   if(!destro_vuoto(ref)){


	canc_sottoalbero_bin(leggi_figlio_dx(ref));

   }


   if(ref != radice){

   temp = ref->leggi_padre();

     if(temp->leggi_figlio_sx() == ref){

//il nodo che è ora ref è figlio sinistro del nodo padre temp, quindi devo rendere
//il puntatore al figlio sinistro del padre nullo.

     temp->inserisci_figlio_sx(NULL);
     num_nodi--;
     }

     else {
//ref è figlio destro di temp

     temp = ref->leggi_padre();

     temp->inserisci_figlio_dx(NULL);
     num_nodi--;

     }


}//fine if(ref != radice)



else {

//Se sono qui vuol dire che ref corrisponde alla radice dell'albero che quindi non ha padre
//per questo lo cancello direttamente con delete.

delete ref;
num_nodi = 0;
}//fine else




}//fine if(ref != NULL)

else {

	cout << "ATTENZIONE: IL NODO PASSATO PER LA CANCELLAZIONE E' NULLO!" << endl;
}



}







template <class T>
bool Albero_bin<T>::albero_vuoto()
{

return (radice == NULL);

}




//Verifica se il nodo passato in input ha un figlio sinistro oppure no.
template <class T>
bool Albero_bin <T>::sinistro_vuoto(nodo ref)
{

if(ref->leggi_figlio_sx() == NULL)return true;
else return false;



}


template <class T>
bool Albero_bin <T>::destro_vuoto(nodo ref)
{

if(ref->leggi_figlio_dx() == NULL)return true;
else return false;



}













template <class T>
typename Albero_bin <T>::nodo Albero_bin <T>::leggi_radice(){

return (radice);

}










template <class T>
typename Albero_bin <T>::nodo Albero_bin <T>::leggi_figlio_sx(nodo ref){

if(ref->leggi_figlio_sx() != NULL)return ref->leggi_figlio_sx();

else
{

	cout << "ERRORE: IL NODO PASSATO IN INPUT NON POSSIEDE UN FIGLIO SINISTRO" << endl;
	throw;

}



}






template <class T>
typename Albero_bin <T>::nodo Albero_bin <T>::leggi_figlio_dx(nodo ref)
{

if(ref->leggi_figlio_dx() != NULL)return ref->leggi_figlio_dx();

else
{

	cout << "ERRORE: IL NODO PASSATO IN INPUT NON POSSIEDE UN FIGLIO DESTRO" << endl;
	throw;

}

}













template <class T>
typename Albero_bin <T>::nodo Albero_bin <T> ::leggi_padre(nodo ref)
{

if(ref != radice)return (ref->leggi_padre());

else
{
	cout << "ATTENZIONE: IL NODO PASSATO IN INPUT E' LA RADICE, QUINDI NON HA UN PADRE." << endl;
    throw;
}





}







template <class T>
T Albero_bin<T>::leggi_nodo(nodo ref)
{

if(ref != NULL)return ref->getValore();
else
{
 cout << "ATTENZIONE: IL NODO PASSATO IN INPUT E' NULLO" << endl;
 throw;



}

}





template <class T>
void Albero_bin<T>::scrivinodo(nodo ref, T valore)
{

if(ref != NULL)
{

ref->inserisci_valore(valore);

}

else cout << "ATTENZIONE: IL NODO PASSATO IN INPUT E' NULLO" << endl;

}



//Inserisco come radice dell'albero il nodo passato in input al metodo.
template <class T>
void Albero_bin <T>::ins_bin_radice(nodo ref)
{

if(radice == NULL)
{
 radice = ref;
 radice->inserisci_figlio_sx(NULL);
 radice->inserisci_figlio_dx(NULL);
 radice->inserisci_padre(NULL);
 num_nodi = 1;

}

else cout << "ERRORE: IL NODO RADICE ESISTE GIA'" << endl;

}




//Crea un figlio sinistro per il nodo passato in input.
//Il nodo che verrà creato avrà i puntatori ai figli NULLI
//e la sua etichetta assumerà un valore casuale.
template <class T>
void Albero_bin <T> ::ins_figlio_sx(nodo ref)
{

if(sinistro_vuoto(ref))
{

ref->inserisci_figlio_sx(new Cella<T>);
ref->leggi_figlio_sx()->inserisci_padre(ref);//il metodo inserisci figlio sx è della classe cella.
ref->leggi_figlio_sx()->inserisci_figlio_sx(NULL);
ref->leggi_figlio_sx()->inserisci_figlio_dx(NULL);
num_nodi++;

}

else cout << "ATTENZIONE: IL NODO PASSATO IN INPUT POSSIEDE GIA' UN FIGLIO SINISTRO" << endl;


}



//Crea un figlio destro per il nodo passato in input.
//Il nodo che verrà creato avrà i puntatori ai figli NULLI
//e la sua etichetta assumerà un valore casuale.
template <class T>
void Albero_bin <T> ::ins_figlio_dx(nodo ref)
{

if(destro_vuoto(ref))
{

ref->inserisci_figlio_dx(new Cella<T>);//il metodo inserisci figlio sx è della classe cella.
ref->leggi_figlio_dx()->inserisci_padre(ref);
ref->leggi_figlio_dx()->inserisci_figlio_sx(NULL);
ref->leggi_figlio_dx()->inserisci_figlio_dx(NULL);
num_nodi++;

}

else cout << "ATTENZIONE: IL NODO PASSATO IN INPUT POSSIEDE GIA' UN FIGLIO DESTRO" << endl;


}










template <class T>
void Albero_bin <T>::visita_in_ampiezza()
{

Coda <nodo> coda(50);
//Coda <nodo> coda2;
nodo temp;
coda.in_coda(radice);


while(!coda.coda_vuota())
{

   temp = coda.leggi_coda();
   cout << temp->getValore() << endl;
   coda.fuori_coda();

   if(!sinistro_vuoto(temp))
   {

   coda.in_coda(leggi_figlio_sx(temp));

   }


   if(!destro_vuoto(temp))
   {
   coda.in_coda(leggi_figlio_dx(temp));

   }


}//fine while



}



template <class T>
void Albero_bin <T>::visita_in_pre_ordine(nodo ref)
{

	cout << ref->getValore() << endl;

	if(!sinistro_vuoto(ref)) visita_in_pre_ordine(leggi_figlio_sx(ref));

	if(!destro_vuoto(ref)) visita_in_pre_ordine(leggi_figlio_dx(ref));


}



template <class T>
void Albero_bin <T>::visita_in_post_ordine(nodo ref)
{

    if(!sinistro_vuoto(ref)) visita_in_post_ordine(leggi_figlio_sx(ref));

    if(!destro_vuoto(ref)) visita_in_post_ordine(leggi_figlio_dx(ref));

    cout << ref->getValore() << endl;





}





#endif /* ALBERI_BIN_H_ */
