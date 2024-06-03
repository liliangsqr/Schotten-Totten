#pragma once
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class Carte
{
protected :

	unsigned int  pCouleur;

public:

	#pragma region GETTERS
	unsigned int& getCouleur() { return pCouleur; }
	void toString();
	#pragma endregion

protected:

	
	#pragma region SETTERS
	void setCouleur(int& couleur) { pCouleur = couleur; }
#pragma endregion


	
};

