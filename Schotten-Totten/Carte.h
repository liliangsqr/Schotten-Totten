#pragma once
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class Carte
{
protected : 
	int pCouleur;

public:

	#pragma region GETTERS
	int getCouleur() { return pCouleur; }
	#pragma endregion

protected:

	#pragma region SETTERS
	void setCouleur(int& couleur) { pCouleur = couleur; }
#pragma endregion


	
};

