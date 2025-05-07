
#ifndef CLASSE_COPPIA_H_
#define CLASSE_COPPIA_H_



template<class K, class E>
class Coppia{

public:


	Coppia();
	Coppia(unsigned int&);
	void setKey(const K);//inserisce il valore del campo chiave
	void setValue(const E);//inserisce il valore
	K getKey();//restituisce la chiave
	E getValue();//restituisce il valore



private:
	K chiave;
	E valore;
    //Coppia *coppia_succ;
};


template <class K, class E>

Coppia<K,E>::Coppia(){}





template <class K, class E>
void Coppia<K,E>::setKey(const K chiave_in)
{

chiave = chiave_in;
}



template <class K, class E>
void Coppia<K,E>::setValue(const E valore_in)
{

valore = valore_in;
}






template <class K, class E>
K Coppia<K,E>::getKey()
{
	return chiave;

}




template <class K, class E>
E Coppia<K,E>::getValue()
{
	return valore;

}






#endif /* CLASSE_COPPIA_H_ */
