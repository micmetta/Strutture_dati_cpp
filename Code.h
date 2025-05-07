
#ifndef CODE_H_
#define CODE_H_
#include <iostream>

using namespace std;

template < class tipoelem >
class Coda
{
	public:
	Coda(int);
	~Coda();
	void creaCoda();
	bool coda_vuota();
	tipoelem leggi_coda();
	void fuori_coda();
	void in_coda(tipoelem);

	private:
	tipoelem *elementi;
	int testa, lung, maxlung;


};




template <class tipoelem> Coda<tipoelem>::Coda(int n)
{
	maxlung = n;
	creaCoda();

};




template <class tipoelem> Coda<tipoelem>::~Coda()
{
	delete[] elementi;

}


template <class tipoelem>
void Coda<tipoelem>::creaCoda()
{
	elementi = new tipoelem[maxlung];
	testa = 0;
	lung = 0;
}





template <class tipoelem>
bool Coda<tipoelem>::coda_vuota()
{
	return (lung == 0);
}





template <class tipoelem> tipoelem Coda<tipoelem>::leggi_coda()
{
	if (coda_vuota()){

		cout  << "ERRORE: LA CODA E' VUOTA NON E' PIU' POSSIBILE LEGGERE ELEMENTI" << endl;
		throw;
	}

	else return (elementi[testa]);

}




template <class tipoelem> void Coda<tipoelem>::fuori_coda()
{
	if(coda_vuota()) cout << "ERRORE: LA CODA E' VUOTA E NON E' PIU' POSSIBILE ESEGUIRE IL FUORICODA" << endl;
    testa = (testa + 1) % maxlung;    lung--;
}




template <class tipoelem> void Coda<tipoelem>::in_coda(tipoelem a)
{
	if(lung != maxlung){
	elementi[(testa+lung) % maxlung] = a;
	lung++;

	}

	else cout << "ATTENZIONE: HAI RAGGIUNTO IL NUMERO MASSIMO DI ELEMENTI CHE POSSONO TROVARSI IN CODA" << endl;

}






#endif /* CODE_H_ */
