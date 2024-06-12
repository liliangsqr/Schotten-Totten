#include "JeuClassique.h"

void JeuClassique::creerJoueurs(unsigned int nbJoueurs)
{
    for (unsigned int i = 0; i < nbJoueurs; i++) {
        string nomJoueur = "Joueur " + to_string(i + 1);
        unique_ptr<Joueur> joueur = make_unique<Joueur>(nomJoueur);
        totalJoueurs.push_back(move(joueur));
    }
}

void JeuClassique::DistribuerCartes(unsigned int nbJoueurs, unsigned int nbCartesMain = 7)
{
    for (unsigned int i; i < total.GetSizeTas(); i++) {

    }
}

void JeuClassique::initialiser(unsigned int nbJoueurs)
{
    creerJoueurs(nbJoueurs);
    // Total est rempli des cartes clan par son constructeur par défaut
    
    // Distribution des cartes
    total.Melanger();
    DistribuerCartes();
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
