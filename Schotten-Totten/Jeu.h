#ifndef JEU_H
#define JEU_H
#include "Frontiere.h"
#include "Joueur.h"
#include "Combinaison.h"


// Jeu est une classe abstraite, ses classes filles sont des singletons
class Jeu
{
public :
	virtual ~Jeu() = default;

protected :
	// ATTRIBUTS
	Frontiere frontiere;

	// CONSTRUCTEURS
	Jeu() = default;

	// METHODES
	virtual void initialiser(unsigned int nbJoueurs = 2) = 0;
	virtual bool terminer() = 0;
	virtual void jouerTour(Joueur& joueurActuel) = 0;
	virtual Combinaison evaluerCombinaisonJoueur() = 0;
};


#endif