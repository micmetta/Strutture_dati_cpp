
#include <iostream>
#include "funzioni_hash.h"

using namespace std;

//implementazioni delle funzioni di hash

valore_di_hash hash(string stringa)
{

	valore_di_hash hash = 5381;
	int l=stringa.length();
	int c;
	for (int i=0;i<l;i++){
		c=stringa[i];
		hash = hash*33 + c;
	}

	return hash;
}




valore_di_hash hash(int numero)
{
	int ris = (numero % 41) % 11;

	return ris;
}




valore_di_hash hash(float numero)
{
	int ris = (numero / 41) / 11;

	return ris;
}


valore_di_hash hash(double numero)
{
	int ris = (numero / 41) / 11;

	return ris;

}

