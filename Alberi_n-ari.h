
#ifndef ALBERI_N_ARI_H_
#define ALBERI_N_ARI_H_
#include "cella_alberi_n-ari.h"
#include <stdlib.h>
#include <iostream>
#include "code.h"

using namespace std;


template <class T>

class Albero_n_ario {

public:

	typedef Cella_n_ari<T>* nodo;
	//costruttore e distruttore
	Albero_n_ario();//costruttore che inizializza l'albero
    ~Albero_n_ario();

    //operatori
    bool albero_vuoto();
    void ins_n_radice(nodo);//inserisce come radice dell'albero n-ario il nodo passato in input
    nodo leggi_radice();//restituisce il nodo radice
    nodo leggi_primo_figlio(nodo);//restituisce il primo figlio (se esiste) del nodo passato in input (se esiste)
    nodo leggi_fratello(nodo);//restituisce il fratello (se esiste) del nodo passato in input (se esiste)
    nodo leggi_padre(nodo);//restituisce il padre (se esiste) del nodo passato in input (se esiste)
    bool foglia(nodo);//restituisce vero se il nodo passato in input è un nodo foglia altrimenti restituisce falso
    bool ultimo_fratello(nodo);//restituisce vero se il nodo passato in input è l'ultimo fratello del suo livello altrimenti restituisce falso
    bool esiste_primo_figlio(nodo);//restituisce vero se il nodo passato in input ha un primo figlio altrimenti restituisce falso
    bool esiste_fratello(nodo);
    bool verifica_primo_figlio(nodo);//verifica se il nodo passato in input è o no un primofiglio

    //nodo fratello_succ(nodo);//restituisce il fratello (se esiste) del nodo passato in input (se esiste)

    //inserisce al nodo di input (che deve appartenere all'albero) come primofiglio l'albero passato
    //come secondo parametro. Se il primo figlio era già occupato (oppure se è NULL) lo si sposta e si inserisce come
    //primofiglio sempre la radice dell'albero passato come secondo parametro, ciò significa che in questo
    //caso il fratello della radice dell'albero passato in input sarà il nodo che era presente come
    //primofiglio di nodo.
    void ins_primo_sottoalbero(nodo, Albero_n_ario<T>&);


    void inserisci_primo_figlio(nodo);//crea un primofiglio per il nodo passato in input(il valore che assumerà l'etichetta sarà casuale)
    void inserisci_nodo_figlio(nodo);//crea un figlio per il nodo passato in input


    //rende la radice dell'albero passato in input, fratello del nodo passato in input,
    //dove quest'ultimo ovviamente deve essere un nodo dell'albero.
    void ins_sottoalbero(nodo, Albero_n_ario<T>&);

    void canc_sottoalbero(nodo);//elimina il sottoalbero che ha come radice il nodo passato in input


    //operatori di scrittura e lettura dei nodi
    T leggi_nodo(nodo);
    //scrive nel nodo passato in input il valore passato come secondo parametro
    void scrivi_nodo(nodo, T);


    int get_num_nodi();
    void visita_in_ampiezza();






private:
    bool appartiene(nodo);
    nodo radice;
    int num_nodi;
};







template <class T>
Albero_n_ario <T>::Albero_n_ario()
{
   num_nodi = 0;
   radice = NULL;

}



template <class T>
Albero_n_ario <T>::~Albero_n_ario(){}



template <class T>
bool Albero_n_ario <T>::albero_vuoto()
{
return (radice == NULL);
}





template <class T>
void Albero_n_ario<T>::ins_n_radice(nodo ref)
{

 if(radice == NULL){

 radice = ref;
 radice->inserisci_padre(NULL);
 radice->inserisci_fratello(NULL);
 radice->inserisci_primo_figlio(NULL);
 num_nodi = 1;

 }

 else cout << "ERRORE: L'ALBERO HA GIA' UNA RADICE QUINDI NON E' POSSIBILE INSERIRNE UN'ALTRA"<<endl;

}



template <class T>
int Albero_n_ario<T>::get_num_nodi()
{
	return num_nodi;
}





template <class T>
typename Albero_n_ario<T>::nodo Albero_n_ario <T>::leggi_radice()
{


  if(!albero_vuoto())return radice;

  else {

	cout << "ATTENZIONE: L'ALBERO E' VUOTO QUINDI NON E' POSSIBILE LEGGERE LA RADICE"<<endl;
    throw;
  }

}




template <class T>
typename Albero_n_ario<T>::nodo Albero_n_ario<T>::leggi_padre(nodo ref)
{

   //if(!appartiene(ref)){

	   //cout << "ERRORE: IL NODO PASSATO IN INPUT NON APPARTIENE ALL'ALBERO" << endl;
       //throw;
   //}


   if(ref != leggi_radice()){

	   return ref->leggi_padre();

   }


   else {

	   cout << "ERRORE: IL NODO PASSATO IN INPUT E' LA RADICE CHE NON HA PADRE!" << endl;
       throw;
   }


}





template <class T>
typename Albero_n_ario<T>::nodo Albero_n_ario<T>::leggi_fratello(nodo ref)
{



  if(!ultimo_fratello(ref)){

     return (ref->leggi_fratello());

   }


  else {
	  cout << "ERRORE: (METODO LEGGI FRATELLO) IL NODO PASSATO IN INPUT NON HA FRATELLI"<<endl;
	  throw;

  }


}










template <class T>
bool Albero_n_ario<T>::foglia(nodo ref)
{

	//if(!appartiene(ref)){

		//cout << "IL NODO PASSATO IN INPUT NON APPARTIENE ALL'ALBERO" << endl;
		//throw;
	//}

	//else

	return (ref->leggi_primofiglio() == NULL);

}




template <class T>
bool Albero_n_ario<T>::ultimo_fratello(nodo ref)
{

    return (ref->leggi_fratello() == NULL);



}




template <class T>
bool Albero_n_ario<T>::esiste_primo_figlio(nodo ref)
{


	if(ref->leggi_primofiglio() == NULL)return false;
	else return true;

}




template <class T>
bool Albero_n_ario<T>::esiste_fratello(nodo ref)
{

	return (!ref->leggi_fratello() == NULL);


}











template <class T>
bool Albero_n_ario<T>::verifica_primo_figlio(nodo ref)
{

	nodo temp = ref->leggi_padre();
	if(leggi_primo_figlio(temp) == ref)return true;

	else return false;


}










template <class T>
typename Albero_n_ario<T>::nodo Albero_n_ario<T>::leggi_primo_figlio(nodo ref)
{


  if(!appartiene(ref)){

			cout << "IL NODO PASSATO IN INPUT NON APPARTIENE ALL'ALBERO" << endl;
			throw;
		}




  if(ref->leggi_primofiglio() != NULL){

	  return ref->leggi_primofiglio();

   }


  else cout << "ERRORE: IL NODO PASSATO IN INPUT NON HA UN PRIMO FIGLIO" <<endl;
  throw;

}







template <class T>
T Albero_n_ario<T>::leggi_nodo(nodo ref)

{

	if(!appartiene(ref)){

			cout << "IL NODO PASSATO IN INPUT NON APPARTIENE ALL'ALBERO" << endl;
			throw;
		}




	else return ref->getValore();

}








template <class T>
void Albero_n_ario<T>::scrivi_nodo(nodo ref, T valore)
{

	ref->inserisci_valore(valore);
}








template <class T>
void Albero_n_ario<T>::visita_in_ampiezza()
{
	Coda <nodo> coda(100);
	nodo temp;
    nodo verifica;
    bool flag = false;

	temp = leggi_radice();
	coda.in_coda(temp);

	while(!coda.coda_vuota()){

		temp = coda.leggi_coda();
		cout << temp->getValore() << endl;
		coda.fuori_coda();
        flag = false;


		if(leggi_radice() == temp && esiste_primo_figlio(leggi_radice())){

			coda.in_coda(leggi_primo_figlio(temp));
            flag = true;
		}

		else {

			if (verifica_primo_figlio(temp)){

				//temp è un primofiglio quindi devo inserire nella coda tutti i suoi fratelli
				//(ovviamente se ci sono)
				//utilizzo la variabile verifica per non perdere il riferimento a temp in modo tale da
				//poter leggere dopo suo figlio (se c'è)

				verifica = temp;
				while(!ultimo_fratello(verifica)){

					  verifica = leggi_fratello(verifica);
					  coda.in_coda(verifica);

				  }

			}

			//ora controllo se il primofiglio di temp esiste

			if(esiste_primo_figlio(temp) && flag == false){

			temp = leggi_primo_figlio(temp);
            coda.in_coda(temp);

			}


            ////////////////////////////


		}//fine else


	}

}












template <class T>
void Albero_n_ario<T>::ins_primo_sottoalbero(nodo ref, Albero_n_ario<T>& albero)
{
	if(!appartiene(ref)){

			cout << "IL NODO PASSATO IN INPUT NON APPARTIENE ALL'ALBERO" << endl;
			throw;
		}




	else if(!albero.albero_vuoto()){


    	//inserisco alla radice dell'albero passato come secondo parametro
    	//il fratello del primofiglio di ref (può essere anche NULL)
    	albero.leggi_radice()->inserisci_fratello(ref->leggi_primofiglio());

    	//inserisco come padre della radice dell'albero passato il nodo ref
    	albero.leggi_radice()->inserisci_padre(ref);

    	//inserisco come primofiglio del nodo ref la radice dell'albero passato in
    	//input
        ref->inserisci_primo_figlio(albero.leggi_radice());

    }//fine if(!albero.albero_vuoto())


    else cout << "ATTENZIONE: L'ALBERO PASSATO IN INPUT COME SECONDO PARAMETRO E' VUOTO!" << endl;



}







template <class T>
void Albero_n_ario<T>::inserisci_primo_figlio(nodo ref)
{

	if(!appartiene(ref)){

			cout << "IL NODO PASSATO IN INPUT NON APPARTIENE ALL'ALBERO" << endl;
			throw;
		}




   if(!esiste_primo_figlio(ref)){


	   ref->inserisci_primo_figlio(new Cella_n_ari <T>);
	   ref->leggi_primofiglio()->inserisci_padre(ref);
	   ref->leggi_primofiglio()->inserisci_fratello(NULL);
	   ref->leggi_primofiglio()->inserisci_primo_figlio(NULL);

	   num_nodi++;
   }



   else {


	   nodo temp = leggi_primo_figlio(ref);

	   ref->inserisci_primo_figlio(new Cella_n_ari <T>);
	   ref->leggi_primofiglio()->inserisci_padre(ref);
	   ref->leggi_primofiglio()->inserisci_fratello(temp);
	   ref->leggi_primofiglio()->inserisci_primo_figlio(NULL);

       num_nodi++;



   }



}

















template <class T>
void Albero_n_ario<T>::ins_sottoalbero(nodo ref, Albero_n_ario<T>& albero)
{

 if(!albero.albero_vuoto()){

	 if(leggi_radice() != ref){//Controllo se ref non è la radice dell'albero corrente perchè se così fosse
		                      //non potrei aggiungergli fratelli.

        //inserisco come fratello della radice dell'albero passato in input il fratello
		//di ref (può essere anche NULL)
		albero.leggi_radice()->inserisci_fratello(ref->leggi_fratello());

		//inserisco come padre della radice dell'albero di input lo stesso padre di ref
		albero.leggi_radice()->inserisci_padre(ref->leggi_padre());

        //inserisco come fratello di ref la radice dell'albero passato come secondo parametro
		ref->inserisci_fratello(albero.leggi_radice());


	 }


	 else {
		cout << "ATTENZIONE: IL NODO PASSATO COME PRIMO PARAMETRO CORRISPONDE ALLA RADICE DELL'ALBERO"<< endl;
	    cout << "A CUI APPARTIENE, QUINDI NON PU0' AVERE FRATELLI" << endl;
	 }

  }

 else {

	 cout << "ATTENZIONE: L'ALBERO PASSATO IN INPUT COME SECONDO PARAMETRO E' VUOTO" << endl;
	 cout << "PER QUESTO NON E' POSSIBILE INSERIRLO COME FRATELLO DI UN ALTRO NODO" << endl;

 }




}







template <class T>
void Albero_n_ario<T>::canc_sottoalbero(nodo ref)
{

	if(!appartiene(ref)){

			cout << "IL NODO PASSATO IN INPUT NON APPARTIENE ALL'ALBERO" << endl;
			throw;
		}



	else if(leggi_radice() == ref){

	    delete radice;
     }

    else {

    	if(ref == leggi_primo_figlio(leggi_radice(ref))){
    		//Se sono qui è perchè ref è un primofiglio

    		if(ultimo_fratello(ref)){

    			//se entro qui significa che ref è un primofiglio e non ha fratelli

    			ref->leggi_padre()->inserisci_primo_figlio(NULL);
    			//ho inserito come primofiglio del padre di ref NULL
    		}

    		//se sono qui vuol dire che ref non è ultimo fratello ma continua ad essere primofiglio
    		//quindi il primofiglio diventa suo fratello
    		else ref->leggi_padre()->inserisci_primo_figlio(ref->leggi_fratello());

    	}


    	else {

    		//se entro qui vuol dire che ref non è un primofiglio quindi ha dei nodi precedenti
    		nodo precedente;
    		nodo corrente;

    		precedente = leggi_primo_figlio(leggi_padre(ref));
    		corrente = leggi_fratello(precedente);

    		while(corrente != ref){

    			precedente = corrente;
    			corrente = leggi_fratello(corrente);

    		}

    		//Quando uscirò dal while corrente sarà proprio ref il nodo che dovrò eliminare

    		//se ref è ultimo fratello allora il puntatore al fratello di precedente dovrà
    		//puntare a NULL
    		if(ultimo_fratello(ref)) precedente->inserisci_fratello(NULL);

    		//altrimenti dovrà puntare al fratello di ref
    		else precedente->inserisci_fratello(leggi_fratello(ref));
    	}





    }


delete ref;

}










template <class T>
bool Albero_n_ario<T>::appartiene(nodo ref)
{

    nodo temp;
    Coda <nodo> coda(100);


    if(leggi_radice() == ref)return true;


    else {

    	temp = leggi_radice();

    	if(esiste_primo_figlio(temp)){

    	    if(leggi_primo_figlio(temp) == ref)return true;


    	    coda.in_coda(leggi_primo_figlio(temp));
    		//la coda adesso contiene il primo figlio della radice

    	    while(!coda.coda_vuota()){

    	    	temp = coda.leggi_coda();
    	    	coda.fuori_coda();

    	    	if(temp == ref)return true;

    	    	if(verifica_primo_figlio(temp)){

                   //se entro qui vuol dire che temp è un primofiglio quindi può inserire
    	    	   //tutti i suoi fratelli nella coda

    	    		while(!ultimo_fratello(temp)){

    	    			temp = leggi_fratello(temp);
    	    			coda.in_coda(temp);

    	    		}

    	    	}

    	    }//fine while


    	    return false;

    	  }

    	  else return false;


     }



}








#endif /* ALBERI_N_ARI_H_ */
