#include "JeuTactique.h"
#include "Regles.h"
#include "Interaction.h"

void JeuTactique::initialiser()
{
    creerJoueurs(Regles::getInstance().getNbJoueurs());  // Crée les joueurs en fonction du nombre défini par les règles
    total.Melanger();  // Mélange le jeu de cartes total
    distribuerCartes(Regles::getInstance().getTailleMain());  // Distribue les cartes aux joueurs
    frontiere = Frontiere(totalJoueurs);  // Initialise la frontière avec les joueurs créés

    total.Melanger();  // Mélange à nouveau le jeu de cartes total

    // Transfère toutes les cartes tactiques restantes dans la pioche tactique
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
    // Crée les joueurs en leur attribuant des noms uniques
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

    // Vérifie si le jeu total contient suffisamment de cartes pour distribuer à tous les joueurs
    if (total.getTaille() < totalCartesNecessaires)
    {
        throw std::runtime_error("Pas assez de cartes pour distribuer a tous les joueurs.");
    }

    // Distribue les cartes aux joueurs
    for (auto& joueur : totalJoueurs)
    {
        for (unsigned int carte = 0; carte < nbCartesMain; carte++)
        {
            // Vérifie si le jeu total est vide avant de retirer une carte
            if (total.estVide())
            {
                throw std::runtime_error("Plus assez de cartes dans le total pour la distribution");
            }
            joueur->ajouterCarteMain(std::move(total.Retirer(0)));
        }
    }

    // Transfère toutes les cartes restantes du jeu total dans la pioche
    while (!total.estVide())
    {
        std::unique_ptr<Carte> carte = std::move(total.Retirer(total.getTaille() - 1));
        pioche.Ajouter(std::move(carte));
    }
}


void JeuTactique::finDePartie()
{
    // À compléter
}


/*const std::shared_ptr<Joueur> JeuTactique::getGagnant() const
{
    for (const auto& joueur : totalJoueurs) {
        // Si le joueur a gagné selon les règles spécifiques du jeu tactique
        if (frontiere.joueurAGagne(joueur)) {
            return joueur;
        }
    }

    // Si aucun joueur n'a gagné
    return nullptr;
}*/


/*bool JeuTactique::terminer()
{
    // Logique pour vérifier si la partie doit se terminer
    // Par exemple, vérifier si toutes les bornes sont revendiquées
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
    // Vérifie si la borne à l'index spécifié est revendicable par le joueur spécifié
    return frontiere.getBorne(index).estRevendicableParJoueur(joueur);
}

void JeuTactique::revendiquerBorne(unsigned int index, const std::shared_ptr<Joueur>& joueur)
{
    // Revendique la borne à l'index spécifié pour le joueur spécifié
    frontiere.revendiquerBorne(index, joueur);
}

void JeuTactique::piocher(std::shared_ptr<Joueur>& joueur)
{
    // Vérifie si la main du joueur est pleine avant de piocher une carte
    if (joueur->getMain().GetSizeTas() == Regles::getInstance().getTailleMain())
    {
        throw std::runtime_error("Vous essayez de piocher alors que la main du joueur est pleine");
    }

    // Vérifie si la pioche est vide avant de permettre au joueur de piocher
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
    // Le joueur pose une carte sur la borne spécifiée
    frontiere.poserCarte(indexBorne, indexCarte, joueur);
}

void JeuTactique::jouerTour(std::shared_ptr<Joueur>& joueur)
{
    // L'interaction du joueur pour choisir une borne et une carte à poser
    unsigned int indexBorne = Interaction::choisirBorne(*this, joueur);
    unsigned int indexCarte = Interaction::choisirCarte(joueur);

    // Le joueur pose une carte sur la borne choisie
    poserCarte(indexBorne, indexCarte, joueur);

    // Vérification si le joueur souhaite revendiquer une borne
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

    // Vérification si la pioche contient des cartes et si la main du joueur n'est pas vide
    if (pioche.GetSizeTas() > 0 && joueur->getMain().GetSizeTas() != 0)
    {
        piocher(joueur);
    }
}