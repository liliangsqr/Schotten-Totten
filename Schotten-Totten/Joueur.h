#pragma once 
#include <string>
#include "Main.h"
#include "TotalClassique.h"
#include "Pioche.h"
using namespace std;

class Joueur
{
private: 
	string pNom;
	Main pMain;
public:
	Joueur(const string& initNom) :pNom(initNom) {}

	string& getNom() { return pNom; }
	void PoserCarte(unsigned int positionCarte, TasDeCartes<Carte> tas);
	void Piocher(Pioche pioche);
};

