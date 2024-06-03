#pragma once
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

template <class T> class Carte
{
protected : 
	T pValeur;
	string pCouleur;
public:

	#pragma region GETTERS
		T getValeur() { return pValeur; }
		string getCouleur() { return pCouleur; }
	#pragma endregion
	void toString() { cout << "La Carte est un \"" << pValeur << " " << pCouleur<<"\""<<endl; }

protected:

	#pragma region SETTERS
	void setValeur(const T& valeur) { pValeur = valeur; }
	void setCouleur(string& couleur) { pCouleur = couleur; }
#pragma endregion


	
};

