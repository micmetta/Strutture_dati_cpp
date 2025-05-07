#include "pile.h"


using namespace std;





template <class Elemento> Pila<Elemento>::Pila()
{

	elementi = new tipoelem[100]; // dimensione standard della pila  MAXLUNGH = 100;
	creaPila();


}





template <class Elemento> Pila<Elemento>::Pila(int N)
{
	elementi = new tipoelem[N]; // dimensione N della pila MAXLUNGH = N;  creaPila(); }
    MAXLUNGH = 100;
    creaPila();
}






template <class Elemento> Pila<Elemento>::~Pila()
{
	delete[] elementi;
}





template <class Elemento> void Pila<Elemento>::creaPila()
{
	testa=0;

}


template <class Elemento> bool Pila<Elemento>::pilaVuota() const
{
	return (testa==0);

}




template <class Elemento> Elemento Pila<Elemento>::leggiPila() const
{

	if(pilaVuota()){

		cout << "ERRORE: LA PILA E' VUOTA NON E' POSSIBILE LEGGERE L'ELEMENTO IN TOP" << endl;
	    throw;
	}
	else return elementi[testa-1];



}



template <class Elemento> void Pila<Elemento>::fuoriPila()
{
	if (!pilaVuota()) testa-=1;

	else {
		cout<<"nessun elemento nella pila"<<endl;

	}

}





template <class Elemento> void Pila<Elemento>::inPila(tipoelem el)
{
	if (testa==MAXLUNGH)  cout<<"raggiunta capacità massima della pila"<<endl;

	else {
		elementi[testa]=el;  testa++;// la testa viene sempre incrementata per questo
		//quando leggo l'elemento dalla pila faccio elementi[testa-1]
	}

}












