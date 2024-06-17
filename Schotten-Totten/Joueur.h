#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include "Main.h"
#include "TotalClassique.h"
#include "Pioche.h"
using namespace std;

// Gère les transferts de cartes concernant la main du joueur, cette dernière étant un attribut de la classe
class Joueur
{
private: 
	string pNom;
	Main pMain;
public:

	Joueur(const string& initNom) : pNom(initNom) { }



	void PoserCarte(unsigned int positionCarte, TasDeCartes<Carte>& tas);
	void Piocher(Pioche& pioche);
	void ajouterCarteMain(unique_ptr<Carte>&& carte) { pMain.Ajouter(move(carte)); }

	const string& getNom() const {
		return pNom;
	}

	const Main& getMain() { return pMain; }
};

#endif