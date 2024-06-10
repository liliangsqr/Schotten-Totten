#pragma once
#include "Joueur.h"
#include "Combinaison.h"include
#include "TotalClassique.h"
#include "TasDeCartes.h"
#include "Jeu.h"
#include "Combinaison.h"

class JeuClassique : public Jeu
{
private:
	TotalClassique total;
	vector<Joueur> totalJoueurs;
	// Frontiere frontiere;

	// Empêche toute instatiation en dehors de la classe
	JeuClassique();

	
public: // Partie publique, sert à accéder à l'instance unique
	static JeuClassique& getInstance() {
		static JeuClassique instance;
		return instance;
	}

	// On empêche toute copie ou assignation
	JeuClassique(const JeuClassique&) = delete;
	JeuClassique& operator=(const JeuClassique&) = delete;

	void initialiser();
	bool terminer();
	void jouerTour(Joueur& joueur);
	Combinaison evaluerCombinaisonJoueur();

	// TasDeCartes<CarteClan> getTotalCarteClassique() { return totalCarteClassique; }

};