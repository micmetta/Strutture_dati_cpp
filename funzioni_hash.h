


#ifndef FUNZIONI_HASH_H_
#define FUNZIONI_HASH_H_
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;



typedef unsigned int valore_di_hash;//il valore_di_hash d'ora in poi indicherà il tipo intero senza segno

//prototipi delle funzioni di hash
valore_di_hash hash(string);
valore_di_hash hash(int);


#endif /* FUNZIONI_HASH_H_ */
