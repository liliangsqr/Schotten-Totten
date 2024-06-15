#ifndef JEUTACTIQUE
#define JEUTACTIQUE

#include "Joueur.h"
#include "TotalTactique.h"
#include "TasDeCartes.h"
#include "Jeu.h"
#include "Combinaison.h"

class JeuTactique : public Jeu
{
private:
	TotalTactique total;
	// vector<shared_ptr<Joueur>> totalJoueurs;
	// Frontiere frontiere;

	// Empêche toute instatiation en dehors de la classe
	JeuTactique();


public: // Partie publique, sert à accéder à l'instance unique
	static JeuTactique& getInstance() {
		static JeuTactique instance;
		return instance;
	}

	// On empêche toute copie ou assignation
	JeuTactique(const JeuTactique&) = delete;
	JeuTactique& operator=(const JeuTactique&) = delete;

	void initialiser();
	bool terminer();
	void jouerTour(Joueur& joueur);

	Combinaison evaluerCombinaisonJoueur();

	// TotalTactique<CarteClan> getTotalCarteClassique() { return totalCarteClassique; }

};

#endif