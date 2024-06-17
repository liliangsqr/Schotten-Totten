#include "Interaction.h"

// Renvoie un unsigned int repr�sentant un des modes de jeu, g�re tous les cas de cassage
unsigned int Interaction::demanderModeJeu()
{
    unsigned int mode;
    bool condition = true;

    while (condition)
    {
        // Affichage::demanderModeJeu();

        // Si le joueur n'a pas entr� un entier
        if (!(cin >> mode))
        {
            cout << "Veuillez entrer un entier valide." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // On v�rifie si l'utilisateur choisit un mode qui existe dans la liste
        else if (mode < 1 || mode > Regles::getInstance().getModesJeu().size())
        {
            condition = false;
        }
    }

    return mode;
}

