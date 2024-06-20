#include "JeuClassiqueExperts.h"

void JeuClassiqueExperts::jouerTour(std::shared_ptr<Joueur>& joueur)
{
    // Revendication de borne(s)
    if (Interaction::joueurVeutRevendiquer()) { // Si le joueur veut revendiquer une ou plusieurs bornes
        bool arreter = false;
        while (!arreter) { // On redemande si la borne n'est pas revendicable, si elle l'est on la revendique et on redemande quand même
            unsigned int indexBorneARevendiquer = Interaction::getBorneARevendiquer(*this);
            if (borneEstRevendicableParJoueur(indexBorneARevendiquer, joueur)) {
                revendiquerBorne(indexBorneARevendiquer, joueur);

                Affichage::borneRevendiquee();
            }
            else {
                Affichage::borneNonRevendicable();
            }
            arreter = Interaction::arreterRevendication(); // Est-ce que le joueur veut essayer de revendiquer d'autres bornes
        }
    }


    unsigned int indexBorne;
    unsigned int indexCarte;

    // Choix de la borne puis de la carte à y poser
    indexBorne = Interaction::choisirBorne(*this, joueur); // Les verifs sont faites dans choisirBorne
    indexCarte = Interaction::choisirCarte(joueur); // Les verifs sont faites dans choisirCarte

    // Pose de la carte
    poserCarte(indexBorne, indexCarte, joueur);

    

    // Si la pioche et la main du joueur ne sont pas vides
    if (pioche.GetSizeTas() != 0 && joueur.get()->getMain().GetSizeTas() != 0) {
        piocher(joueur);
    }

    // Fin du tour
}
