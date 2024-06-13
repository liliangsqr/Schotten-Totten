#ifndef REGLE_H

#define REGLE_H
#include <vector>
#include <string>

using namespace std;

class Regles
{
private:
	unsigned int pNbJoueur;
	vector<string> pModesJeu;

	// initialiser les règles
public:

	Regles(unsigned int initNbJoueurs = 2,vector<string> iniModesJeu={"Classique","Tactique"});
	vector<string>& getModesJeux() { return pModesJeu; }
	unsigned int getNBjoueurs() { return pNbJoueur; }

protected:

};

#endif // !REGLE_H


