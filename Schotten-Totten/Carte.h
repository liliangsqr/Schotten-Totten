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
	string getCouleur() { return pCouleur; }
	#pragma endregion

protected:

	#pragma region SETTERS
	void setCouleur(string& couleur) { pCouleur = couleur; }
#pragma endregion


	
};

