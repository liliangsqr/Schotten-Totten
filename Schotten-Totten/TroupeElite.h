#ifndef TROUPEELITE_H
#define TROUPEELITE_H
#include "CarteTactique.h"

// Carte tactique se jouant comme une carte clan dont la valeur et/ou la valeur sont d�termin�es par le joueur au moment de la revendication
class TroupeElite : public CarteTactique
{
private:
	//pNom
	//pValeur
	//pCouleur
public:
	TroupeElite(unsigned int initValeur,unsigned int initCouleur,const string& initNom):CarteTactique(initValeur,initCouleur,initNom) {}
};

#endif TROUPEELITE_H