#include "Interaction.h"

unsigned int Interaction::choixPlage(unsigned int min, unsigned int max)
{
    unsigned int mode;
    bool condition = true;

    while (condition)
    {
        // Si le joueur n'a pas entr� un entier
        if (!(cin >> mode))
        {
            cout << "Veuillez entrer un entier valide." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // On v�rifie si l'utilisateur choisit une option qui existe
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
        throw runtime_error("Probl�me avec un choix True/False");
    }
}

// Renvoie un unsigned int repr�sentant un des modes de jeu, g�re tous les cas de cassage
unsigned int Interaction::demanderModeJeu()
{
    Affichage::ChoixMode();
    return choixPlage(1, (unsigned int)Regles::getInstance().getModesJeu().size()); // choix = 1;
}

unsigned int Interaction::choisirBorne(Jeu& jeu, const shared_ptr<Joueur>& joueur)
{
    Affichage::demanderBorne();

    while (true) { // Si plein alors infini /!\ 
        unsigned int borne = choixPlage(1, Regles::getInstance().getNbBornes()) - 1; // -1 car pour nous les indexBorne commencent � 0, et pour les joueurs � 1

        // Si la borne est pleine
        if (jeu.getFrontiere().getBorne(borne).getTasBorne(joueur).GetSizeTas() == Regles::getInstance().getCapaciteMaxTasBorne()) {
            Affichage::bornePleine();
        }
        else {
            return borne;
        }
    }
}

unsigned int Interaction::choisirCarte(const shared_ptr<Joueur>& joueur)
{
    Affichage::demanderCarte();     // Affichage::demanderCarte()

    return choixPlage(1, joueur.get()->getMain().GetSizeTas()) - 1; // idem pour le -1
}

bool Interaction::joueurVeutRevendiquer()
{
    Affichage::demanderPhaseRevendication();
  
    return choixTrueFalse();
}

unsigned int Interaction::getBorneARevendiquer(Jeu& jeu)
{
    Affichage::demanderBorneARevendiquer();

    return choixPlage(1, Regles::getInstance().getNbBornes()) - 1;
}

bool Interaction::arreterRevendication()
{
    Affichage::demanderArretRevendication();
    
    return choixTrueFalse();
}

