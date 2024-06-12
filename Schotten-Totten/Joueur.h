#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
using namespace std;


class Joueur
{
private: 
	string pNom;
public:
	Joueur(const string& initNom) :pNom(initNom) {}

	const string& getNom() { return pNom; }
	void Jouer();
	void Piocher();
	void Revendiquer();
};

#endif