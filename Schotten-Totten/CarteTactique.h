#ifndef CARTETACTIQUE_H
#define CARTETACTIQUE_H
#include "Carte.h"
#include "iomanip"

// Carte ayant un comportement spécial, utilisée dans la variante tactique du jeu
class CarteTactique : public Carte
{
private:
	// unsigned int pValeur;
	// unsigned int pCouleur
	string pNom;
public:

	CarteTactique(unsigned int initValeur, unsigned int initCouleur, const string& initNom) :Carte(initValeur, initCouleur), pNom(initNom) {}

	const string& getNom() const{ return pNom; }
	void toString() { cout << "Carte [" << pNom << "," << pCouleur << "] et as pour effet : " << pNom << endl; }

};

#endif CARTETACTIQUE_H