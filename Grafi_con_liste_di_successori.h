
#ifndef GRAFO_CON_LISTE_DI_SUCCESSORI_H_
#define GRAFO_CON_LISTE_DI_SUCCESSORI_H_
#include <iostream>
#include <stdlib.h>
//#include "grafi.h"
#include "liste.h"
#include "grafo_con_liste_di_successori.h"




//creo la classe nodo del grafo
class NodoG{

 public:

	NodoG(int i){

		NodoId = i;
	}


	NodoG(){NodoId = - 1;}////////////////////////possibile errore

	//NodoG(){}
	int getId(){return NodoId;}
	void setId(int id){NodoId = id;}


 private:
	int NodoId;
};





//creo la classe info_arco per il grafo
template <class P>

class info_arco
{

 public:

	P peso;
	NodoG _to;

	//NodoG getNodoG(){

		//return _to;

	//}

};



template <class E, class P>
class info_nodo {

public:

E etichetta;
bool vuoto;
void *info;

Lista_circ < info_arco<P> > archi;//lista di archi del nodo


info_nodo(){

	info = 0;
	vuoto = true;
    //archi = NULL;


}

};



//Ora creo l'implementazione per il grafo con liste di adiacenza

template <class E, class P>
class Grafo_lista //: public Grafo<E, P, NodoG>

{

public:

typedef E etichetta;
typedef P peso;
typedef NodoG nodo;
//typedef Arco_<peso, nodo> arco;
//typedef Grafo<etichetta, peso, nodo> Grafo_;
//typedef typename Grafo_::lista_nodi lista_nodi;
//typedef typename Grafo_::pos_lista_nodi pos_lista_nodi;
typedef Lista_circ<nodo*> lista_nodi;



typedef Lista_circ <nodo*>::posizione pos_lista_nodi;


//costruttore e distruttore
Grafo_lista(int);//il valore passato in input al costruttore permette di capire di che dimensione creare
//il vettore dei nodi del grafo


~Grafo_lista();


//operatori


bool grafo_vuoto() const; //restituisce true se il grafo è vuoto altrimenti restituisce false
void inserisci_nodo(nodo&);//inserisce un nodo nel grafo
void inserisci_arco(nodo, nodo, peso);//inserisce un arco tra i due nodi passati in input inserendo anche il peso
void cancella_nodo(nodo);//cancella il nodo del grafo passato in input
void cancella_arco(nodo, nodo);//cancella l'arco che collega i due nodi di input
bool esiste_nodo(nodo);//restituisce true se il nodo passato in input è presente nel grafo altrimenti restituisce false
bool esiste_arco(nodo,nodo);//restituisce true se il nodo passato come primo parametro ha un arco uscente che va nel secondo nodo passato in input altrimenti restituisce false
void lista_adiacenti(nodo);//restituisce una lista che conterrà tutti i nodi adiacenti al nodo passato
//in input

lista_nodi list_nodi();//restituisce una lista di tipo lista_nodi che conterrà al proprio interno tutti i nodi del grafo
void inserisci_nodo_in_lista_nodi(nodo);
etichetta leggi_etichetta(nodo) const;//(SAREBBE LEGGI NODO) restituisce il valore dell'etichetta presente nel nodo passato in ingresso (solo se il nodo appartiene al grafo corrente)
peso leggi_arco(nodo, nodo) const;
void scrivi_etichetta(nodo, etichetta);//scrive il valore dell'etichetta passata come secondo parametro
//nel nodo passato in input come primo parametro

peso leggi_peso(nodo, nodo) const;//restituisce il peso dell'arco che collega il nodo n1 al nodo n2 passati in input
void scrivi_peso(nodo, nodo, peso);//scrive il peso passato come terzo parametro nell'arco che collega i due nodi
//passati in input

bool path_more_than (Grafo_lista <int,int> G, nodo src, int k);

void stampa_nodi();








int num_nodi(){
	return nodi;

}//restituisce il numero dei nodi del grafo
int num_archi(){
	return archi;
}//restituisce il numero degli archi del grafo



private:

info_nodo<E,P> *matrice;

int dimensione;
int nodi; //numero dei nodi
int archi; //numero degli archi


};





template <class E, class P>
Grafo_lista<E,P>::Grafo_lista(int dimensione_vettore)
{
	dimensione = dimensione_vettore;
	nodi = 0;
	archi = 0;
	matrice = new info_nodo<E,P>[dimensione];




	for(int i=0;i<dimensione;i++){

		matrice[i].vuoto = true;
	}

}





template<class E, class P>
Grafo_lista<E, P>::~Grafo_lista()
{
	delete [] matrice;
}





template<class E, class P>
bool Grafo_lista<E,P>::grafo_vuoto() const
{
	return (nodi == 0);

}




template <class E, class P>
void Grafo_lista<E,P>::inserisci_nodo(nodo& ref)
{
	int n = 0;
	bool trovato = false;;


	if(nodi < dimensione){//controllo che il vettore non sia pieno

		for(int i = 0; i<dimensione && !trovato;i++){

			if(matrice[i].vuoto){

				matrice[i].vuoto = false;
				n = i;
			    trovato = true;
			}

		}



		ref.setId(n);//inserisco nell'id del nodo passato in input
		             //la sua posizione nel vettore del grafo

		nodi++;//incremento il numero di nodi




	}


	else cout << "ATTENZIONE: IL VETTORE CHE CONTIENE TUTTI I NODI DEL GRAFO E' PIENO E NON E' POSSIBILE AGGIUNGERE ALTRI ELEMENTI" << endl;



}



template <class E, class P>
void Grafo_lista<E,P>::inserisci_arco(nodo n1, nodo n2, peso valore_peso){

info_arco <P> nuovo_arco;//creo un nuovo arco

nuovo_arco.peso = valore_peso;//inserisco come peso quello passato in input
nuovo_arco._to = n2;//dico che il nuovo arco collega il nodo n1 al nodo n2


//Vado nella cella del vettore dove si trova n1 che mi dice (n1.getId), vado nel suo puntatore
//alla lista degli archi (archi), inserisco il nuovo arco nella lista passando come primo parametro
//il nuovo arco creato e come secondo la cella della lista dove inserire il nuovo nodo che corrisponde
//esattamente alla cella del primolista in modo tale da poter effettuare l'inserimento in testa della
//lista circolare.
matrice[n1.getId()].archi.inserisci_nodo(nuovo_arco, matrice[n1.getId()].archi.leggi_primolista());


archi++;

}





template <class E, class P>
void Grafo_lista<E,P>::cancella_nodo(nodo ref)
{
   bool trovato = false;
   int i;
   nodo temp;

   //verifico con il for se c'è qualche nodo del grafo che ha un arco uscente nel nodo ref
   //che devo cancellare, perchè se cosi' fosse dovrò cancellarlo.
   for(i=0;i<dimensione;i++){

	 trovato = false;

	   if(matrice[i].vuoto == false){

		   //se entro qui vuol dire che nella posizione i-esima del vettore c'è un
		   //potenziale nodo che potrebbe avere nella propria lista di adiacenza il nodo da cancellare

		    if(!matrice[i].archi.lista_vuota()){//Se la lista di adiacenza di questo nodo non è vuota
		        //entro per verificare che non ci sia un arco che collega questo nodo al nodo che dovrò
		        //cancellare

		        typename Lista_circ <info_arco<P> >::posizione arco_temp;

		        arco_temp = matrice[i].archi.leggi_primolista();

		        //ora arco_temp è il primolista della lista di adiacenza

		        if(!matrice[i].archi.verifica_finelista(arco_temp) && !trovato){

///////////////////////////////////////////RIPETILO
		        	 if(matrice[i].archi.leggi_elemento(arco_temp)._to.getId() == ref.getId()){
		        		//Ho trovato che questo nodo ha nella proprio lista adiacenti il nodo
		        		//che devo cancellare!!
		        		matrice[i].archi.cancella_cella(arco_temp);
		        		trovato = true;

		        		arco_temp = matrice[i].archi.leggi_succ(arco_temp);
		        	 }

		         }

		    }

	    }

   }//fine for


   //A questo punto avrò eliminato il nodo da cancellare da tutte le liste di adiacenze in cui era presente
   //quindi posso procedere con la sua totale cancellazione

   matrice[ref.getId()].vuoto = true;//Ora la cella del vettore dove si trovava ref è stata liberata
   nodi--;


}







template <class E, class P>
void Grafo_lista<E,P>::cancella_arco(nodo n1, nodo n2)
{
   typename Lista_circ < info_arco <P> >::posizione p;

   p = matrice[n1.getId()].archi.leggi_primolista();//p = primolista della lista di adiacenza di n1

   bool trovato = false;

   while(!matrice[n1.getId()].archi.verifica_finelista(p) && !trovato){

	   if(matrice[n1.getId()].archi.leggi_elemento(p)._to.getId() == n2.getId()){
		   //Abbiamo trovato l'arco da cancellare
             trovato = true;


	   }

	   else p = matrice[n1.getId()].archi.leggi_succ(p);


   }//fine while


   //Se ho trovato l'arco che congiunge n1 a n2 allora lo elimino dalla lista di adiacenza di n1
   if(trovato) matrice[n1.getId()].archi.cancella_cella(p);

}






template <class E, class P>
bool Grafo_lista<E,P>::esiste_nodo(nodo ref)
{

	if(ref.getId() < 0)return false;
	else return (!matrice[ref.getId()].vuoto);


}



template <class E, class P>
bool Grafo_lista<E,P>::esiste_arco(nodo n1, nodo n2){

	typename Lista_circ<info_arco <P> >::posizione p;


	p = matrice[n1.getId()].archi.leggi_primolista();


	while(!matrice[n1.getId()].archi.verifica_finelista(p)){

		if(matrice[n1.getId()].archi.leggi_elemento(p)._to.getId() == n2.getId()){

			return true;

		}

		else p = matrice[n1.getId()].archi.leggi_succ(p);



	}



return false;

}




template <class E, class P>
void Grafo_lista<E,P>::lista_adiacenti(nodo ref)
{

	lista_nodi lista;

	typename Lista_circ < info_arco <P> >::posizione p;

	int i = 0;


	if(!matrice[ref.getId()].vuoto){//se nelal posizione della matrice che mi dice il nodo c'è una cella allora
		 //vuol dire che quel nodo passato in input esiste

	    p = matrice[ref.getId()].archi.leggi_primolista();


		while(!matrice[ref.getId()].archi.verifica_finelista(p)){// se in questa posizione del vettore c'è un nodo

			//allora carica tutti i suoi nodi adiacenti in lista.
			//Se il nodo preso in considerazione non ha nessun nodo adiacente allora non inserisce nulla
		    //in lista

		    i = matrice[ref.getId()].archi.leggi_elemento(p)._to.getId();

		    //essendo che lista può contenere nodi di tipo <NodoG*> io devo passargli come primo parametro
		   //per fare l'inserisci un puntatore di tipo NodoG ed è proprio quello che faccio con il new.
		   //come secondo parametro invece gli passo il suo primolista in modo tale da poter
		   //effettuare l'inserimento in testa

		    lista.inserisci_nodo(new NodoG(i), lista.leggi_primolista());
            p = matrice[ref.getId()].archi.leggi_succ(p);

		}

		//Dopo aver inserito tutti i nodi nella lista di adiacenza la stampo.
		 pos_lista_nodi p;

		 p = lista.leggi_primolista();

		 while(!lista.verifica_finelista(p)){

               int id = 0;
               id = lista.leggi_elemento(p)->getId();
               cout << matrice[id].etichetta <<endl;

               p = lista.leggi_succ(p);

		 }


	}


	else cout << "IL NODO NON E' PRESENTE NEL GRAFO" << endl;


}






template<class E, class P>
typename Grafo_lista<E, P>::lista_nodi Grafo_lista<E, P>::list_nodi()
{

	lista_nodi list;


	for (int i = 0; i < dimensione; i++)  {

		if (!matrice[i].vuoto) {

			//list.inserisci_nodo(new NodoG(i), list.leggi_primolista());
		    list.inserisci_nodo(new NodoG(i), list.leggi_primolista());
			matrice[i].vuoto = false;


		}

	}




	return list;


}









template <class E, class P>
typename Grafo_lista<E,P>::etichetta Grafo_lista<E,P>::leggi_etichetta(nodo ref) const
{

    if(!matrice[ref.getId()].vuoto){

	   return matrice[ref.getId()].etichetta;

       }



    else {

	cout << "ERRORE: LA POSIZIONE DEL VETTORE DOVE SI DOVREBBE TROVARE IL NODO E' VUOTA"<<endl;
	throw;
     }


}




template <class E, class P>
void Grafo_lista<E,P>::scrivi_etichetta(nodo ref, etichetta valore){

	if(!matrice[ref.getId()].vuoto){

		matrice[ref.getId()].etichetta = valore;

	}

	else cout << "IL NODO PASSATO IN INPUT DICE DI TROVARSI IN UNA POSIZIONE DEL VETTORE CHE E' VUOTA" << endl;


}




template <class E, class P>
typename Grafo_lista<E,P>::peso Grafo_lista<E,P>::leggi_peso(nodo n1, nodo n2) const
{

    bool trovato = false;
	typename Lista_circ<info_arco <P> > ::posizione p;

	p = matrice[n1.getId()].archi.leggi_primolista();

    while(!matrice[n1.getId()].archi.verifica_finelista(p) && !trovato){

    	if(matrice[n1.getId()].archi.leggi_elemento(p)._to.getId() == n2.getId()){

    	    //vuol dire che ho trovato l'arco di cui devo restituire il peso

    	    trovato = true;

    	}


    	//altrimenti continuo a scorrere la lista di adiacenza
    	else p = matrice[n1.getId()].archi.leggi_succ(p);


    }



    if(trovato)return matrice[n1.getId()].archi.leggi_elemento(p).peso;

    else {
    	cout << "NON ESISTE UN ARCO CHE COLLEGA IL PRIMO NODO DI INPUT AL SECONDO" << endl;
    	throw;
    }

}




template <class E, class P>
void Grafo_lista<E,P>::scrivi_peso(nodo n1, nodo n2, peso valore)
{


	if(!matrice[n1.getId()].vuoto){

		typename Lista_circ <info_arco <P> >::posizione p;
	    bool agg_effettuato = false;

		p = matrice[n1.getId()].archi.leggi_primolista();

		while(!matrice[n1.getId()].archi.verifica_finelista(p) && !agg_effettuato){

			if(matrice[n1.getId()].archi.leggi_elemento(p)._to.getId() == n2.getId()){

				//Ho trovato l'arco che collega il nodo1 al nodo2 nella lista di adiacenza di n1

				  info_arco <P> nuovo_arco;//creo il nuovo arco
                  nuovo_arco._to = n2;
				  nuovo_arco.peso = valore;

				  agg_effettuato = true;
                  matrice[n1.getId()].archi.scrivi_nodo(nuovo_arco, p);

			}


			else p = matrice[n1.getId()].archi.leggi_succ(p);//altrimenti continuo a scandire la lista

		}


         if(!agg_effettuato)cout << "L'ARCO CHE COLLEGA IL PRIMO NODO DI INPUT AL SECONDO NON E' PRESENTE NEL GRAFO" << endl;





	}


	else cout << "ERRORE: IL PRIMO NODO PASSATO IN INPUT DICE DI TROVARSI IN UNA POSIZIONE DEL VETTORE"<<endl;
	     cout << "CHE E' ATTUALMENTE VUOTA" << endl;

}





template <class E, class P>
typename Grafo_lista<E,P>::peso Grafo_lista<E,P>::leggi_arco(nodo n1, nodo n2) const
{

    typename Lista_circ<info_arco <P> >::posizione p;
    bool trovato = false;

	p = matrice[n1.getId()].archi.leggi_primolista();


	while(!matrice[n1.getId()].archi.verifica_finelista(p) && !trovato){

		if(matrice[n1.getId()].archi.leggi_elemento(p)._to.getId() == n2.getId()){
			trovato = true;

		}

		else p = matrice[n1.getId()].archi.leggi_succ(p);



	}


	if(trovato) return matrice[n1.getId()].archi.leggi_elemento(p).peso;

	else {

		cout << "L'ARCO TRA IL PRIMO NODO PASSATO IN INPUT E IL SECONDO NON APPARTIENE AL GRAFO" << endl;
	    throw;
	}

}






template <class E, class P>
void Grafo_lista<E,P>::stampa_nodi(){


	for (int i = 0; i < dimensione; i++)  {

			if (!matrice[i].vuoto) {

                cout << matrice[i].etichetta << endl;

             }

	}



}




/*
template <class E, class P>
bool Grafo_lista<E,P> ::path_more_than (Grafo_lista <int,int> G, nodo src, int k)
{

	 typename Lista_circ<info_arco <P> >::posizione p;
	 Lista_circ <info_arco <P> > lista_nodi_adiacenti_src;
	 Lista_circ<info_arco<P> > lista_cammino;

	 info_arco <P> var;

	 var.peso = 0;//inserisco come peso quello passato in input
	 var._to = src;

     lista_cammino.inserisci_nodo(var, lista_cammino.leggi_primolista());

	 int peso_cammino = 0;







	 p = matrice[src.getId()].archi.leggi_primolista();




	 while(!matrice[src.getId()].archi.verifica_finelista(p)){



		 lista_nodi_adiacenti_src.inserisci_nodo(p->leggi_elemento(), lista_nodi_adiacenti_src.leggi_primolista());

		 p = matrice[src.getId()].archi.leggi_succ(p);




	 }


	 //adesso nella lista nodi adiacenti src avrò tutti i nodi adiacenti al nodo passato in input.
	 //Per ogni nodo della lista devo verificare se c'è un cammino senza cicli

	 //p = lista_nodi_adiacenti_src.leggi_primolista();

	 typename Lista_circ<info_arco <P> >::posizione p_lista_adiacenti;
	 typename Lista_circ<info_arco <P> >::posizione a;


	 //ora controllo per ogni nodo della lista se ha nella propria lista adiacenti il nodo passato in input
	 //dall'utente

	 p_lista_adiacenti = lista_nodi_adiacenti_src.leggi_primolista();




	 bool esci = false;
	 typename Lista_circ<info_arco <P> >::posizione var_verifica;

	 var_verifica = matrice[p_lista_adiacenti->leggi_elemento()._to.getId()].archi.leggi_primolista();

	 while(!matrice[p_lista_adiacenti->leggi_elemento()._to.getId()].archi.verifica_finelista(var_verifica) && !esci){



           if(var_verifica->leggi_elemento()._to.getId() == src.getId()){



        	   a = p_lista_adiacenti->leggi_cella_succ();
        	   lista_nodi_adiacenti_src.cancella_cella(p_lista_adiacenti);

        	   p_lista_adiacenti = a;
               esci = true;


           }


           else p_lista_adiacenti = p_lista_adiacenti->leggi_cella_succ();



	 }
	 cout << "fafa" << endl;

	 //Al termine del while avrò nella lista_nodi_adiacenti_src solo quelli che non avevavo un
	 //arco entrante in src


	 p_lista_adiacenti = lista_nodi_adiacenti_src.leggi_primolista();


	 int id_nodo = p->leggi_elemento()._to.getId();

	 //p_lista_adiacenti è il nodo della lista adiacenti


	 while(!lista_nodi_adiacenti_src.lista_vuota()){

		 Lista_circ <info_arco<P> > lista_nuova;

		 //fino a quando nella lista adiacenti del nodo passato in input c'è un elemento
		 //Verifico se per ogni elemento esiste un cammino senza cicli che ha un peso maggiore di k
         //man mano che verifico il cammino aggiungo gli elementi del cammino in un'altra lista che chiamo
		 //lista cammino



         //inserisco il nodo p_lista_adiacenti nella nuova lista
		 lista_nuova.inserisci_nodo(p_lista_adiacenti->leggi_elemento(), lista_nuova.leggi_primolista());

		 //Verifico anche per lui che nessun nodo presente nella sua lista di adiacenza sia collegato a lui
		 while(!matrice[p_lista_adiacenti->leggi_elemento()._to.getId()].archi.verifica_finelista(p_lista_adiacenti)){



		           if(p_lista_adiacenti->leggi_elemento()._to.getId() == id_nodo){



		        	   p_lista_adiacenti = lista_nodi_adiacenti_src.leggi_succ(p_lista_adiacenti);
		        	   lista_nodi_adiacenti_src.cancella_cella(p_lista_adiacenti);



		           }


		           //qui invece controllo se il nodo può essere inserito nella lista cammino
		           //potrò isìnserirlo solo quando verifico che per ogni nodo presente in lista cammino
		           else {
		        	   typename Lista_circ<info_arco <P> >::posizione pos_lista_cammino;
		        	   //devo vedere se il nodo
		        	   if(!lista_cammino.lista_vuota()){

		        		   //se entro qui vuol dire che devo controllare che il nodo
		        		   //che sto prendendo in considerazione non abbia nella propria lista di adiacenza
		        		   //tutti i nodi del cammino presenti in lista cammino


		        		   pos_lista_cammino = lista_cammino.leggi_primolista();

		        		   bool non_possibile = false;

		        		   while(!lista_cammino.verifica_finelista(pos_lista_cammino) && !non_possibile){

                                if(p_lista_adiacenti->leggi_elemento()._to.getId() == pos_lista_cammino->leggi_elemento()._to.getId()){

                                	//vuol dire che se aggiungo quindi non potendolo inserire esco dal ciclo while
                                	//utilizzando la variabile non possibile;

                                	non_possibile = true;
                                }



		        		   }

		        		   //se arrivo qui vuol dire che posso inserire il nodo nella lista cammino
		        		   lista_cammino.inserisci_nodo(pos_lista_cammino->leggi_elemento(), lista_cammino.leggi_primolista());

		        	   }


		        	   else {

		        		   lista_cammino.inserisci_nodo(pos_lista_cammino->leggi_elemento(), lista_cammino.leggi_primolista());
		        	   }
		           }



			 }//


		 //calcolo il peso del cammino
		 typename Lista_circ<info_arco <P> >::posizione pos;
		 pos = lista_cammino.leggi_primolista();



		 while(!lista_cammino.lista_vuota()){

			 peso_cammino = peso_cammino + pos->leggi_elemento().peso;
			 pos = pos->leggi_cella_succ();

		 }


		 if(peso_cammino > k) {

			 //stampo il cammino trovato

			 pos = lista_cammino.leggi_primolista();

			 while(!lista_cammino.verifica_finelista(pos)){


			    cout << matrice[pos->leggi_elemento()._to.getId()].etichetta << endl;

			    pos = pos->leggi_cella_succ();


			 }

			 cout << endl << endl;

			 return true;



		 }




	 }

	 return false;

}

*/





#endif /* GRAFO_CON_LISTE_DI_SUCCESSORI_H_ */
