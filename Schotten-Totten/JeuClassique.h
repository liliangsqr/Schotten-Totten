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


	// Emp�che toute instatiation en dehors de la classe
	JeuClassique();

	// M�thodes d'initialisation

	// Cr�e les joueurs, les r�f�rence avec des shared_ptr, et les ajoute dans totalJoueurs
	void creerJoueurs(unsigned int nbJoueurs);

	// Distribue les cartes dans les mains et la pioche au d�but du jeu
	void distribuerCartes(unsigned int nbCartesMain);

	// Initialisation de tout le jeu, distribution des cartes dans les mains et dans la pioche, cr�ation des joueurs
	void initialiser();

	// Actions �ventuelles � r�aliser � la fin de la partie (vide pour l'instant)
	void finDePartie();

	
public: // Partie publique, sert � acc�der � l'instance unique

	// Permet d'acc�der � l'instance et appelle le contructeur par d�faut au premier appel
	static JeuClassique& getInstance() {
		static JeuClassique instance;
		return instance;
	}

	// On emp�che toute copie ou assignation
	JeuClassique(const JeuClassique&) = delete;
	void operator=(const JeuClassique&) = delete;


	// Parcourt tous les joueurs pour v�rifier si l'un deux a gagn�, et si c'est le cas retourne une r�f�rence const vers lui
	const std::shared_ptr<Joueur>& getGagnant() const;
	
	// Si la partie est bien termin�e, y met fin et fait les nettoyages n�cessaires en appelant finDePartie(), sinon renvoie false
	bool terminer();
	
	void jouerTour(Joueur& joueur);
	
	Combinaison evaluerCombinaisonJoueur();




};


#endif