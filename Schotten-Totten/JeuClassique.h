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

	// M�thodes d'initialisation

	// Cr�e les joueurs, les r�f�rence avec des unique_ptr, et les ajoute dans totalJoueurs
	void creerJoueurs(unsigned int nbJoueurs);

	// Distribue les cartes dans les mains et la pioche au d�but du jeu
	void DistribuerCartes(unsigned int nbCartesMain = 7);

	
public: // Partie publique, sert � acc�der � l'instance unique

	// Permet d'acc�der � l'instance et appelle le contructeur par d�faut au premier appel
	static JeuClassique& getInstance() {
		static JeuClassique instance;
		return instance;
	}

	// Initialisation de tout le jeu, distribution des cartes dans les mains et dans la pioche, cr�ation des joueurs
	void initialiser(unsigned int nbJoueurs);

	bool terminer();
	
	void jouerTour(Joueur& joueur);
	
	Combinaison evaluerCombinaisonJoueur();


	// On emp�che toute copie ou assignation
	JeuClassique(const JeuClassique&) = delete;
	void operator=(const JeuClassique&) = delete;

};


#endif