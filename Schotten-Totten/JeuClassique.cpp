#include "JeuClassique.h"

void JeuClassique::creerJoueurs(unsigned int nbJoueurs)
{
    for (unsigned int i = 0; i < nbJoueurs; i++) {
        string nomJoueur = "Joueur " + to_string(i + 1);
        shared_ptr<Joueur> joueur = make_shared<Joueur>(nomJoueur);
        totalJoueurs.push_back(move(joueur));
    }
}

// Distribue nbCartesMain par joueur et le reste dans la pioche
void JeuClassique::distribuerCartes(unsigned int nbCartesMain)
{
    // A chaque joueur
    for (unsigned int joueur = 0; joueur < totalJoueurs.size(); joueur++) {
        // On distribue nbCartesMain cartes
        for (unsigned int carte = 0; carte < nbCartesMain; carte++) {
            // Déplace la carte de l'indice 0 du total vers la main du joueur
            // grâce au fait que les vectors se réorganisent tout seuls
            totalJoueurs[joueur]->ajouterCarteMain(move(total.Retirer(0)));
        }
    }

    // Le reste va dans la pioche
    while (!total.estVide()) {
        unique_ptr<Carte> carte = move(total.Retirer(total.getTaille() - 1));
        pioche.Ajouter(move(carte));
    }
}

// Met le jeu complètement en place
void JeuClassique::initialiser(unsigned int nbJoueurs)
{
    creerJoueurs(nbJoueurs);
    // Total est rempli des cartes clan par son constructeur par défaut
    // Distribution des cartes
    total.Melanger();
    distribuerCartes();
}

bool JeuClassique::terminer()
{
	// Aller chercher dans la map qu'il y a dans frontiere pour savoir si un joueur a gagné
    return false;
}

void JeuClassique::jouerTour(Joueur& joueur)
{
    /*
	jouer
    poser carte
    verifier victoire
    */
}

Combinaison JeuClassique::evaluerCombinaisonJoueur()
{
    Combinaison a;
    return  a;;;
}
