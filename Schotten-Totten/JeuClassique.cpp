#include "JeuClassique.h"

void JeuClassique::initialiser()
{
	//initialisation du tas de carte par defaut avec TotalClassqieur();

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

	
}

void JeuClassique::jouerTour(Joueur& joueur)
{

}

Combinaison JeuClassique::evaluerCombinaisonJoueur()
{
	
}
