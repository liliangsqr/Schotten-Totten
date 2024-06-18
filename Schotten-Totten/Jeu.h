#ifndef JEU_H
#define JEU_H
#include "Frontiere.h"
#include "Joueur.h"
#include "Combinaison.h"


// Jeu est une classe abstraite, ses classes filles sont des singletons qui g�rent le fonctionnement interne des m�caniques de jeu
// et les met � disposition pour qu'elles soient utilis�es par Application
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

	// M�thodes d'initialisation

	// Cr�e les joueurs, les r�f�rence avec des shared_ptr, et les ajoute dans totalJoueurs
	virtual void creerJoueurs(unsigned int nbJoueurs) = 0;

	// Distribue les cartes dans les mains et la/les pioches au d�but du jeu
	virtual void distribuerCartes(unsigned int nbCartesMain) = 0;

	// Initialisation de tout le jeu, distribution des cartes dans les mains et dans la/les pioches, cr�ation des joueurs
	virtual void initialiser() = 0;

	// Actions �ventuelles � r�aliser � la fin de la partie
	virtual void finDePartie() = 0;


public :
	// M�thodes

	// Parcourt tous les joueurs pour v�rifier si l'un deux a gagn�, et si c'est le cas retourne une r�f�rence const vers lui
	virtual const std::shared_ptr<Joueur> getGagnant() const = 0;

	// Si la partie est bien termin�e, y met fin et fait les nettoyages n�cessaires en appelant finDePartie(), sinon renvoie false
	virtual bool terminer() = 0;

	// Appelle estRevendicableParJoueur sur la borne � l'index index de la fronti�re
	virtual bool borneEstRevendicableParJoueur(unsigned int index, const shared_ptr<Joueur> joueur) const = 0;

	// Appelle simplement revendiquerBorne de la classe Frontiere
	virtual void revendiquerBorne(unsigned int index, const shared_ptr<Joueur>& joueur) = 0;

	// Fait piocher le joueur pass� en param�tres
	// L�ve une exception si la main du joueur est pleine ou si la pioche est vide
	virtual void piocher(shared_ptr<Joueur>& joueur) = 0;

	// D�place la carte de la position indexCarte de la main du joueur vers le tasBorne associ� au joueur sur la borne num�ro indexBorne
	// L�ve une exception si les valeurs entr�es sont incorrectes, donc faire les v�rifications avant
	virtual void poserCarte(unsigned int indexBorne, unsigned int indexCarte, shared_ptr<Joueur>& joueur) = 0;

	// Joue un tour entier, contient donc la logique d'un tour sp�cifique � un mode de jeu, � �crire dans la classe fille
	virtual void jouerTour(shared_ptr<Joueur>& joueur) = 0;



	virtual const vector<shared_ptr<Joueur>>& getJoueurs() { return totalJoueurs; }
	virtual const Frontiere& getFrontiere() { return frontiere; }
};



#endif