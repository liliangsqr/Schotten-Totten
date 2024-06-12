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

	// Empêche toute instatiation en dehors de la classe
	JeuClassique();

	// Méthodes d'initialisation

	// Crée les joueurs, les référence avec des unique_ptr, et les ajoute dans totalJoueurs
	void creerJoueurs(unsigned int nbJoueurs);

	// Distribue les cartes dans les mains et la pioche au début du jeu
	void DistribuerCartes(unsigned int nbCartesMain = 7);

	
public: // Partie publique, sert à accéder à l'instance unique

	// Permet d'accéder à l'instance et appelle le contructeur par défaut au premier appel
	static JeuClassique& getInstance() {
		static JeuClassique instance;
		return instance;
	}

	// Initialisation de tout le jeu, distribution des cartes dans les mains et dans la pioche, création des joueurs
	void initialiser(unsigned int nbJoueurs);

	bool terminer();
	
	void jouerTour(Joueur& joueur);
	
	Combinaison evaluerCombinaisonJoueur();


	// On empêche toute copie ou assignation
	JeuClassique(const JeuClassique&) = delete;
	void operator=(const JeuClassique&) = delete;

};


#endif