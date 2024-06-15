#include "JeuClassique.h"


JeuClassique::JeuClassique() : Jeu()
{
    initialiser();
}


// Crée les joueurs et les insère dans totalJoueurs
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
    // Vérifie qu'il y a assez de cartes dans le total pour distribuer à tous les joueurs
    size_t totalCartesNecessaires = nbCartesMain * totalJoueurs.size();
    if (total.getTaille() < totalCartesNecessaires) {
        throw runtime_error("Pas assez de cartes pour distribuer à tous les joueurs.");
    }


    // A chaque joueur
    for (auto& joueur : totalJoueurs) {
        // On distribue nbCartesMain cartes
        for (unsigned int carte = 0; carte < nbCartesMain; carte++) {
            if (total.estVide()) {
                throw runtime_error("Plus assez de carte dans Total pour la distribution");
            }

            // Déplace la carte de l'indice 0 du total vers la main du joueur
            // grâce au fait que les vectors se réorganisent tout seuls
            joueur->ajouterCarteMain(move(total.Retirer(0)));
        }
    }

    // Le reste va dans la pioche
    while (!total.estVide()) {
        unique_ptr<Carte> carte = move(total.Retirer(total.getTaille() - 1));
        pioche.Ajouter(move(carte));
    }
}

// Met le jeu complètement en place
void JeuClassique::initialiser()
{
    // Total est rempli des cartes clan par son constructeur par défaut
    creerJoueurs(Regles::getInstance().getNbJoueurs());

    // Distribution des cartes
    total.Melanger();
    distribuerCartes(Regles::getInstance().getTailleMain());
    frontiere = Frontiere(totalJoueurs);
}

bool JeuClassique::terminer()
{
	// Aller chercher dans la map qu'il y a dans frontiere pour savoir si un joueur a gagné

    return true;
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
    return a;
}
