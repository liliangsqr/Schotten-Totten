#pragma once 
#include <string>
using namespace std;

class Joueur
{
private: 
	string pNom;
public:
	Joueur(const string& initNom) :pNom(initNom) {}

	string& getNom() { return pNom; }
	void Jouer();
	void Piocher();
	void Revendiquer();
};

