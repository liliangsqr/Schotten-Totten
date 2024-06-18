#ifndef JEU_H
#define JEU_H
#include "Frontiere.h"
#include "Joueur.h"
#include "Combinaison.h"


// Jeu est une classe abstraite, ses classes filles sont des singletons qui gèrent le fonctionnement interne des mécaniques de jeu
// et les met à disposition pour qu'elles soient utilisées par Application
class Jeu
{
public :
	virtual ~Jeu() = default;

protected :
	// ATTRIBUTS
	vector<shared_ptr<Joueur>> totalJoueurs;
	Frontiere frontiere;
	Pioche pioche;

	// CONSTRUCTEURS

	Jeu() = default;

	// Méthodes d'initialisation

	// Crée les joueurs, les référence avec des shared_ptr, et les ajoute dans totalJoueurs
	virtual void creerJoueurs(unsigned int nbJoueurs) = 0;

	// Distribue les cartes dans les mains et la/les pioches au début du jeu
	virtual void distribuerCartes(unsigned int nbCartesMain) = 0;

	// Initialisation de tout le jeu, distribution des cartes dans les mains et dans la/les pioches, création des joueurs
	virtual void initialiser() = 0;

	// Actions éventuelles à réaliser à la fin de la partie
	virtual void finDePartie() = 0;


public :
	// Méthodes

	// Parcourt tous les joueurs pour vérifier si l'un deux a gagné, et si c'est le cas retourne une référence const vers lui
	virtual const std::shared_ptr<Joueur> getGagnant() const = 0;

	// Si la partie est bien terminée, y met fin et fait les nettoyages nécessaires en appelant finDePartie(), sinon renvoie false
	virtual bool terminer() = 0;

	// Appelle estRevendicableParJoueur sur la borne à l'index index de la frontière
	virtual bool borneEstRevendicableParJoueur(unsigned int index, const shared_ptr<Joueur> joueur) const = 0;

	// Appelle simplement revendiquerBorne de la classe Frontiere
	virtual void revendiquerBorne(unsigned int index, const shared_ptr<Joueur>& joueur) = 0;

	// Fait piocher le joueur passé en paramètres
	// Lève une exception si la main du joueur est pleine ou si la pioche est vide
	virtual void piocher(shared_ptr<Joueur>& joueur) = 0;

	// Déplace la carte de la position indexCarte de la main du joueur vers le tasBorne associé au joueur sur la borne numéro indexBorne
	// Lève une exception si les valeurs entrées sont incorrectes, donc faire les vérifications avant
	virtual void poserCarte(unsigned int indexBorne, unsigned int indexCarte, shared_ptr<Joueur>& joueur) = 0;

	// Joue un tour entier, contient donc la logique d'un tour spécifique à un mode de jeu, à écrire dans la classe fille
	virtual void jouerTour(shared_ptr<Joueur>& joueur) = 0;



	virtual const vector<shared_ptr<Joueur>>& getJoueurs() { return totalJoueurs; }
	virtual const Frontiere& getFrontiere() { return frontiere; }
};



#endif