#ifndef JEUCLASSIQUE_H
#define JEUCLASSIQUE_H

#include "Joueur.h"
#include "TotalClassique.h"
#include "TasDeCartes.h"
#include "Jeu.h"
#include "Combinaison.h"

class JeuClassique : public Jeu
{
private:
	TotalClassique total;
	vector<unique_ptr<Joueur>> totalJoueurs;
	Frontiere frontiere;

	// Emp�che toute instatiation en dehors de la classe
	JeuClassique();

	
public: // Partie publique, sert � acc�der � l'instance unique
	static JeuClassique& getInstance() {
		static JeuClassique instance;
		return instance;
	}

	// On emp�che toute copie ou assignation
	JeuClassique(const JeuClassique&) = delete;
	JeuClassique& operator=(const JeuClassique&) = delete;

	void initialiser(unsigned int nbJoueurs = 2);
	bool terminer();
	void jouerTour(Joueur& joueur);
	Combinaison evaluerCombinaisonJoueur();

	// TotalClassique<CarteClan> getTotalCarteClassique() { return totalCarteClassique; }

};


#endif