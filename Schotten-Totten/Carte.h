#pragma once
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

 class Carte
{
protected : 
	string pCouleur;
public:

	#pragma region GETTERS
		T getValeur() { return pValeur; }
		string getCouleur() { return pCouleur; }
	#pragma endregion
		void toString();

protected:

	#pragma region SETTERS
	void setValeur(const T& valeur) { pValeur = valeur; }
	void setCouleur(string& couleur) { pCouleur = couleur; }
#pragma endregion


	
};

