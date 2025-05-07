#ifndef PILE_H_
#define PILE_H_
#include <iostream>
#include <string>
#include <cstdlib>
#include "pile.h"

//implementazione tramite vettore con template


const int MAXLUNGH = 100;


template <class elemento>

class Pila
{

public:

	 typedef elemento tipoelem;

	 //da adesso tipoelemen = allo stesso tipo di elemento

	 Pila(); // costruttore
	 Pila(int);
	 ~Pila(); // distruttore
	 void creaPila();//operatori
	 bool pilaVuota() const;
	 tipoelem leggiPila() const;
	 void fuoriPila();
	 void inPila(tipoelem);







private:

	 tipoelem *elementi;
	 int testa;
};
















#endif /* PILE_H_ */
