#include "Interaction.h"

unsigned int Interaction::choixPlage(unsigned int min, unsigned int max)
{
    unsigned int mode;
    bool condition = true;

    while (condition)
    {
        // Si le joueur n'a pas entré un entier
        if (!(cin >> mode))
        {
            cout << "Veuillez entrer un entier valide." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // On vérifie si l'utilisateur choisit une option qui existe
        else if (mode >= min && mode <= max)
        {
            condition = false;
        }
        else {
            cout << "Cette option n'existe pas." << endl;
        }
    }

    return mode;
}

bool Interaction::choixTrueFalse()
{
    unsigned int choix = choixPlage(1, 2);
    if (choix == 1) {
        return true;
    }
    else if (choix == 2) {
        return false;
    }
    else {
        throw runtime_error("Problème avec un choix True/False");
    }
}

// Renvoie un unsigned int représentant un des modes de jeu, gère tous les cas de cassage
unsigned int Interaction::demanderModeJeu()
{
    // Affichage::demanderModeJeu();
    cout << "quel mode de jeu ?" << endl;

    return choixPlage(1, (unsigned int)Regles::getInstance().getModesJeu().size());
}

unsigned int Interaction::choisirBorne(Jeu& jeu, const shared_ptr<Joueur>& joueur)
{
    // Affichage::demanderBorne();
    cout << "sur quelle borne poser ?" << endl;

    while (true) {
        unsigned int borne = choixPlage(1, Regles::getInstance().getNbBornes()) - 1; // -1 car pour nous les indexBorne commencent à 0, et pour les joueurs à 1

        // Si la borne est pleine
        if (jeu.getFrontiere().getBorne(borne).getTasBorne(joueur).GetSizeTas() == Regles::getInstance().getCapaciteMaxTasBorne()) {
            // Affichage::bornePleine();
            cout << "borne pleine" << endl;
        }
        else {
            return borne;
        }
    }
}

unsigned int Interaction::choisirCarte(const shared_ptr<Joueur>& joueur)
{
    // Affichage::demanderCarte()
    cout << "quelle carte poser ?" << endl;

    return choixPlage(1, joueur.get()->getMain().GetSizeTas()) - 1; // idem pour le -1
}

bool Interaction::joueurVeutRevendiquer()
{
    // Affichage::demanderPhaseRevendication();
    cout << "tu veux revendiquer ?" << endl;

    return choixTrueFalse();
}

unsigned int Interaction::getBorneARevendiquer(Jeu& jeu)
{
    // Affichage::demanderBorneARevendiquer();
    cout << "revendiquer quelle borne ?" << endl;

    return choixPlage(1, Regles::getInstance().getNbBornes()) - 1;
}

bool Interaction::arreterRevendication()
{
    // Affichage::demanderArretRevendication();
    cout << "arreter revendication ?" << endl;
    
    return choixTrueFalse();
}

