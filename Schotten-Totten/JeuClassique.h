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
	// vector<shared_ptr<Joueur>> totalJoueurs;
	// Frontiere frontiere;
	// Pioche pioche;


	// Empêche toute instatiation en dehors de la classe
	JeuClassique();

	// Méthodes d'initialisation

	// Crée les joueurs, les référence avec des shared_ptr, et les ajoute dans totalJoueurs
	void creerJoueurs(unsigned int nbJoueurs);

	// Distribue les cartes dans les mains et la pioche au début du jeu
	void distribuerCartes(unsigned int nbCartesMain);

	// Initialisation de tout le jeu, distribution des cartes dans les mains et dans la pioche, création des joueurs
	void initialiser();

	// Actions éventuelles à réaliser à la fin de la partie (vide pour l'instant)
	void finDePartie();

	
public: // Partie publique, sert à accéder à l'instance unique

	// Permet d'accéder à l'instance et appelle le contructeur par défaut au premier appel
	static JeuClassique& getInstance() {
		static JeuClassique instance;
		return instance;
	}

	// On empêche toute copie ou assignation
	JeuClassique(const JeuClassique&) = delete;
	void operator=(const JeuClassique&) = delete;


	// Parcourt tous les joueurs pour vérifier si l'un deux a gagné, et si c'est le cas retourne une référence const vers lui
	const std::shared_ptr<Joueur>& getGagnant() const;
	
	// Si la partie est bien terminée, y met fin et fait les nettoyages nécessaires en appelant finDePartie(), sinon renvoie false
	bool terminer();
	
	void jouerTour(Joueur& joueur);
	
	Combinaison evaluerCombinaisonJoueur();




};


#endif