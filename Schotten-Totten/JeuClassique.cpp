#include "JeuClassique.h"

void JeuClassique::initialiser(unsigned int nbJoueurs =2)// initialisation des cartes création des joueurs.
{
	//initialisation du tas de carte par defaut avec TotalClassqieur();
	//initialisation des bornes dans Frontiere();

	string nomJoueur;
	for (unsigned int i = 1; i <= nbJoueurs; i++)
	{
		nomJoueur = "Joueur" + i;
		unique_ptr<Joueur> joueur = make_unique<Joueur>(nomJoueur);
		totalJoueurs.push_back(joueur);
	}
}

bool JeuClassique::terminer()
{
	//aller chercher dans la map qu'il y a dans frontiere pour savoir si un joueur a gagner

}

void JeuClassique::jouerTour(Joueur& joueur)
{
	joueur.Jouer();
	joueur.Piocher();
}

Combinaison JeuClassique::evaluerCombinaisonJoueur()
{
	
}
