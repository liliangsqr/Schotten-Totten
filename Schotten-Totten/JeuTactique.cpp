#include "JeuTactique.h"
#include "Regles.h"
#include "Interaction.h"

void JeuTactique::initialiser()
{
    creerJoueurs(Regles::getInstance().getNbJoueurs());  // Cr�e les joueurs en fonction du nombre d�fini par les r�gles
    total.Melanger();  // M�lange le jeu de cartes total
    distribuerCartes(Regles::getInstance().getTailleMain());  // Distribue les cartes aux joueurs
    frontiere = Frontiere(totalJoueurs);  // Initialise la fronti�re avec les joueurs cr��s

    total.Melanger();  // M�lange � nouveau le jeu de cartes total

    // Transf�re toutes les cartes tactiques restantes dans la pioche tactique
    while (total.getTaille() > 0)
    {
        auto carte = std::unique_ptr<CarteTactique>(dynamic_cast<CarteTactique*>(total.Retirer(0).release()));
        if (carte)
        {
            piocheTactique.Ajouter(std::move(carte));
        }
    }
}

void JeuTactique::creerJoueurs(unsigned int nbJoueurs)
{
    // Cr�e les joueurs en leur attribuant des noms uniques
    for (unsigned int i = 0; i < nbJoueurs; i++)
    {
        std::string nomJoueur = "Joueur " + std::to_string(i + 1);
        std::shared_ptr<Joueur> joueur = std::make_shared<Joueur>(nomJoueur);
        totalJoueurs.push_back(std::move(joueur));
    }
}

void JeuTactique::distribuerCartes(unsigned int nbCartesMain)
{
    size_t totalCartesNecessaires = nbCartesMain * totalJoueurs.size();

    // V�rifie si le jeu total contient suffisamment de cartes pour distribuer � tous les joueurs
    if (total.getTaille() < totalCartesNecessaires)
    {
        throw std::runtime_error("Pas assez de cartes pour distribuer a tous les joueurs.");
    }

    // Distribue les cartes aux joueurs
    for (auto& joueur : totalJoueurs)
    {
        for (unsigned int carte = 0; carte < nbCartesMain; carte++)
        {
            // V�rifie si le jeu total est vide avant de retirer une carte
            if (total.estVide())
            {
                throw std::runtime_error("Plus assez de cartes dans le total pour la distribution");
            }
            joueur->ajouterCarteMain(std::move(total.Retirer(0)));
        }
    }

    // Transf�re toutes les cartes restantes du jeu total dans la pioche
    while (!total.estVide())
    {
        std::unique_ptr<Carte> carte = std::move(total.Retirer(total.getTaille() - 1));
        pioche.Ajouter(std::move(carte));
    }
}


void JeuTactique::finDePartie()
{
    // � compl�ter
}


/*const std::shared_ptr<Joueur> JeuTactique::getGagnant() const
{
    for (const auto& joueur : totalJoueurs) {
        // Si le joueur a gagn� selon les r�gles sp�cifiques du jeu tactique
        if (frontiere.joueurAGagne(joueur)) {
            return joueur;
        }
    }

    // Si aucun joueur n'a gagn�
    return nullptr;
}*/


/*bool JeuTactique::terminer()
{
    // Logique pour v�rifier si la partie doit se terminer
    // Par exemple, v�rifier si toutes les bornes sont revendiqu�es
    for (const auto& borne : frontiere.getBorne())
    {
        if (!borne.estRevendiquee())
        {
            return false;
        }
    }
    return true;
}*/



bool JeuTactique::borneEstRevendicableParJoueur(unsigned int index, const std::shared_ptr<Joueur> joueur) const
{
    // V�rifie si la borne � l'index sp�cifi� est revendicable par le joueur sp�cifi�
    return frontiere.getBorne(index).estRevendicableParJoueur(joueur);
}

void JeuTactique::revendiquerBorne(unsigned int index, const std::shared_ptr<Joueur>& joueur)
{
    // Revendique la borne � l'index sp�cifi� pour le joueur sp�cifi�
    frontiere.revendiquerBorne(index, joueur);
}

void JeuTactique::piocher(std::shared_ptr<Joueur>& joueur)
{
    // V�rifie si la main du joueur est pleine avant de piocher une carte
    if (joueur->getMain().GetSizeTas() == Regles::getInstance().getTailleMain())
    {
        throw std::runtime_error("Vous essayez de piocher alors que la main du joueur est pleine");
    }

    // V�rifie si la pioche est vide avant de permettre au joueur de piocher
    if (pioche.GetSizeTas() == 0)
    {
        throw std::runtime_error("Vous essayez de piocher alors que la pioche est vide");
    }

    // Le joueur pioche une carte de la pioche principale
    joueur->Piocher(pioche);

    // Si la pioche tactique contient des cartes, le joueur en pioche une
    if (piocheTactique.GetSizeTas() > 0)
    {
        auto carteTactique = piocheTactique.piocherCarte();
        joueur->ajouterCarteMain(std::move(carteTactique));
    }
}

void JeuTactique::poserCarte(unsigned int indexBorne, unsigned int indexCarte, std::shared_ptr<Joueur>& joueur)
{
    // Le joueur pose une carte sur la borne sp�cifi�e
    frontiere.poserCarte(indexBorne, indexCarte, joueur);
}

void JeuTactique::jouerTour(std::shared_ptr<Joueur>& joueur)
{
    // L'interaction du joueur pour choisir une borne et une carte � poser
    unsigned int indexBorne = Interaction::choisirBorne(*this, joueur);
    unsigned int indexCarte = Interaction::choisirCarte(joueur);

    // Le joueur pose une carte sur la borne choisie
    poserCarte(indexBorne, indexCarte, joueur);

    // V�rification si le joueur souhaite revendiquer une borne
    if (Interaction::joueurVeutRevendiquer())
    {
        bool arreter = false;
        while (!arreter)
        {
            unsigned int indexBorneARevendiquer = Interaction::getBorneARevendiquer(*this);
            if (borneEstRevendicableParJoueur(indexBorneARevendiquer, joueur))
            {
                revendiquerBorne(indexBorneARevendiquer, joueur);
                Affichage::borneRevendiquee();
            }
            else
            {
                Affichage::borneNonRevendicable();
            }
            arreter = Interaction::arreterRevendication();
        }
    }

    // V�rification si la pioche contient des cartes et si la main du joueur n'est pas vide
    if (pioche.GetSizeTas() > 0 && joueur->getMain().GetSizeTas() != 0)
    {
        piocher(joueur);
    }
}