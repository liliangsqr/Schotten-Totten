#ifndef JOUEUR_H
#define JOUEUR_H

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

	Joueur(const string& initNom) : pNom(initNom) { }


    const string& getNom() const {
        return pNom;
    }
	void PoserCarte(unsigned int positionCarte, TasDeCartes<Carte>& tas);
	void Piocher(Pioche& pioche);
	void ajouterCarteMain(unique_ptr<Carte>&& carte) { pMain.Ajouter(move(carte)); }
};

#endif