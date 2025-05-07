
#ifndef DIZIONARI_H_
#define DIZIONARI_H_
#include <iostream>
#include <stdlib.h>
#include "dizionari.h"
#include "liste.h"
#include "funzioni_hash.h"
#include "classe_coppia.h"


template <class K, class E>//k = chiave, E = valore

class Dizionario
{

   public:

	//costruttore e distruttore
	Dizionario(unsigned int);//il valore passato in input determinerà la lunghezza del vettore dinamico (tabella)
	                        //che conterrà gli elementi
	~Dizionario();

	//operatori
	bool dizionario_vuoto();//restituisce true se il dizionario è vuoto altrimenti restituisce false
	bool elemento_appartiene(K);//restituisce true se la chiave dell'elemento passato in input appartiene al dizionario altrimenti restituisce falso
    E recupera(const K&);//restituisce il valore dell'elemento la cui chiave è stata inserita in in input (se questa appartiene al dizionario)
	void inserisci_elemento(K,E);//inserisce una coppia chiave-valore all'interno del dizionario (solo se quella coppia chiave-valore non è stata già inserita)
	void cancella_elemento(const K&);//elimina la coppia chiave-valore passata in input dal dizionario(se è presente)
    unsigned int dimensione_dizionario();//restituisce il numero di coppie chiave-valore (quindi di elementi) del dizionario
    unsigned int H(const K&);//restituisce il valore della funzione hash applicata all'elemento passato in ingresso
    void stampa_dizionario();
    void stampa_hash(string);






   private:

    //hash <E> hash;
    unsigned int lunghezza;
    unsigned int num_elementi;
    Lista_circ< Coppia<K,E> > *tabella;


};

template <class K, class E>
Dizionario<K,E>::Dizionario(unsigned int dimensione_vet)
{

 lunghezza = dimensione_vet;
 num_elementi = 0;
 tabella = new Lista_circ< Coppia <K,E> > [lunghezza];

}


template <class K, class E>
Dizionario<K,E>::~Dizionario()
{

delete [] tabella;// cancella tutto il vettore che conteneva le liste di trabocco

}


template <class K, class E>
bool Dizionario<K,E>::dizionario_vuoto()
{
	return (num_elementi == 0);
}




template <class K, class E>
bool Dizionario<K,E>::elemento_appartiene(K ref)
{

typename Lista_circ< Coppia <K,E> >::posizione indice;
bool trovato = false;
unsigned int posizione_vet = H(ref);

//indice sarà la prima cella della lista che si trova in posizione_vet del vettore
indice = tabella[posizione_vet].leggi_primolista();


//il ciclo while permette di scandire tutta la lista che si trova in posizione_vet del vettore.
//Il primo predicato controlla se siamo arrivati alla fine della lista grazie al fatto che essendo
//la lista implementata come lista circolare la sua prima cella vera e propria è una cella fittizia
//che serve proprio per capire se siamo arrivati alla fine della lista oppure no.
//Quindi se già inizialmente la cella indice corrisponde alla cella fittizia lo scorrimento della lista si
//interrompe perchè vuol dire che non ci sono elementi in quella lista.
//Se invece ci sono elementi nella lista, ovviamente, indice inizialmente non sarà la cella fittizia ma bensì
//la prima cella "utile" della lista e quindi si partirà con la scansione.
//Se si trova l'elemento con la stessa chiave inserita in input trovato sarà uguale a true e quindi si uscirà
//subito dopo dal while indipendentemente dal fatto se la lista è stata scendita tutta oppure no.
while(!tabella[posizione_vet].verifica_finelista(indice) && !trovato){

	if(ref == tabella[posizione_vet].leggi_elemento(indice).getKey()){

		trovato = true;

	}

	indice = tabella[posizione_vet].leggi_succ(indice);

}

return trovato;


}











template <class K, class E>
E Dizionario<K,E>::recupera(const K& chiave_in)
{

	typename Lista_circ< Coppia <K,E> >::posizione indice;
	//bool trovato = false;
	unsigned int posizione_vet = H(chiave_in);

	//indice sarà la prima cella della lista che si trova in posizione_vet del vettore
	indice = tabella[posizione_vet].leggi_primolista();


	while(!tabella[posizione_vet].verifica_finelista(indice)){

		if(chiave_in == tabella[posizione_vet].leggi_elemento(indice).getKey()){

			return tabella[posizione_vet].leggi_elemento(indice).getValue();

		}

		indice = tabella[posizione_vet].leggi_succ(indice);

	}


    cout << "ERRORE: LA CHIAVE INSERITA NON E' PRESENTE NEL DIZIONARIO, QUINDI NON E' POSSIBILE" << endl;
    cout << "RESTITUIRE ALCUN VALORE" << endl;
    throw;



}












/*
template <class K, class E>
void Dizionario<K,E>::stampa_hash(string nome)
{

cout << H(nome) << endl;

}

*/














template <class K, class E>
void Dizionario<K,E>::inserisci_elemento(K chiave_in, E valore_in)
{

K chiave;
E valore;


//////////////////////////////Variabili che servono per non inserire un duplicato
typename Lista_circ< Coppia <K,E> >::posizione indice;
bool esiste = false;
unsigned int posizione_vet = H(chiave_in);
/////////////////////////////


chiave = chiave_in;
valore = valore_in;


Coppia<K, E>temp;
temp.setKey(chiave);
temp.setValue(valore);


//verifico se la coppia chiave-valore passata in input già è presente nel dizionario//


indice = tabella[posizione_vet].leggi_primolista();//inizialmente indice sarà la prima cella della lista
//che si trova in posizione_vet del vettore di liste (tabella)


//Nella condizione del while varifico che la cella indice non sia quella fittizia perchè altrimenti vorrebbe dire
//che ho finito di scorrere tutta la lista e quindi sarà la variabile -esiste- che mi dirà all'uscita del ciclo
//se quella coppia è stata trovata oppure no.
//Ovviamente se ancora non ho finito di scorrere tutta la lista ma la coppia è già stata trovata allora
//vuol dire che posso già uscire dal while e avvisare l'utente.
while(!tabella[posizione_vet].verifica_finelista(indice) && !esiste){

	if(chiave_in == tabella[posizione_vet].leggi_elemento(indice).getKey() && valore_in == tabella[posizione_vet].leggi_elemento(indice).getValue()){

		esiste = true;

	}

	indice = tabella[posizione_vet].leggi_succ(indice);

}
//////////////////////////////////////////////////////////////////////////////////////


     if(esiste){
	      cout << "ATTENZIONE: LA COPPIA CHIAVE-VALORE INSERITA IN INPUT E' GIA' PRESENTE NEL DIZIONARIO!"<<endl;
          cout << "QUINDI L'OPERAZIONE DI INSERIMENTO NON E' ANDATA A BUON FINE"<<endl;
      }



//Se la coppia non si trovava già nel dizionario allora inserisco la nuova coppia
     else {

          tabella[H(chiave)].inserisci_nodo(temp, tabella[H(chiave)].leggi_primolista());
          num_elementi++;

       }


}







template <class K, class E>
void Dizionario<K,E>::cancella_elemento(const K& chiave_in)
{

	typename Lista_circ< Coppia<K,E> >::posizione indice;
    unsigned int posizione_vet = H(chiave_in);
    bool trovato = false;


    indice = tabella[posizione_vet].leggi_primolista(); //ora indice sarà il primo elemento della lista


    while(!tabella[posizione_vet].verifica_finelista(indice) && !trovato){

    	if(chiave_in == tabella[posizione_vet].leggi_elemento(indice).getKey()){

           trovato = true;
         }

    	else indice = tabella[posizione_vet].leggi_succ(indice);

    }

    //I motivi dell'uscita dal while possono essere due:
    //1) Ho finito di scandire la lista in posizione_vet e non ho trovato l'elemento
    //2)torvato = true e quindi ho trovato l'elemento

    if(!trovato)cout << "ATTENZIONE: NEL DIZIONARIO NON E' PRESENTE NESSUN ELEMENTO CON CHIAVE UGUALE A QUELLA PASSATA IN INPUT"<<endl;

    else {//Significa che ho trovato l'elemento da cancellare

    	tabella[posizione_vet].cancella_cella(indice);//lo cancello dalla lista in posizione vet
    	num_elementi--;

    }


}









template <class K, class E>
unsigned int Dizionario<K,E>::dimensione_dizionario()
{
	return num_elementi;
}





template <class K, class E>
unsigned int Dizionario<K,E>::H(const K& chiave_in)
{

return (hash(chiave_in) % lunghezza);

}



template <class K, class E>
void Dizionario<K,E>::stampa_dizionario()
{
	typename Lista_circ< Coppia<K,E> >::posizione indice;




	for(int unsigned i=0;i<lunghezza;i++){

	    indice = tabella[i].leggi_primolista(); //ora indice sarà il primo elemento della lista


	    while(!tabella[i].verifica_finelista(indice)){

	    	cout << tabella[i].leggi_elemento(indice).getKey() << endl;
	    	cout << tabella[i].leggi_elemento(indice).getValue() << endl;
	    	cout << endl;

	        indice = tabella[i].leggi_succ(indice);

	    }



	}//fine for


}








#endif /* DIZIONARI_H_ */
