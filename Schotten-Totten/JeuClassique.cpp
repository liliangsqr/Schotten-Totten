#include "JeuClassique.h"


JeuClassique::JeuClassique() : Jeu()
{
    initialiser();
}


// Cr�e les joueurs et les ins�re dans totalJoueurs
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
    // V�rifie qu'il y a assez de cartes dans le total pour distribuer � tous les joueurs
    size_t totalCartesNecessaires = nbCartesMain * totalJoueurs.size();
    if (total.getTaille() < totalCartesNecessaires) {
        throw runtime_error("Pas assez de cartes pour distribuer a tous les joueurs.");
    }


    // A chaque joueur
    for (auto& joueur : totalJoueurs) {
        // On distribue nbCartesMain cartes
        for (unsigned int carte = 0; carte < nbCartesMain; carte++) {
            if (total.estVide()) {
                throw runtime_error("Plus assez de carte dans total pour la distribution");
            }

            // D�place la carte de l'indice 0 du total vers la main du joueur
            // gr�ce au fait que les vectors se r�organisent tout seuls
            joueur->ajouterCarteMain(move(total.Retirer(0)));
        }
    }

    // Le reste va dans la pioche
    while (!total.estVide()) {
        unique_ptr<Carte> carte = move(total.Retirer(total.getTaille() - 1));
        pioche.Ajouter(move(carte));
    }
}

// Met le jeu compl�tement en place
void JeuClassique::initialiser()
{
    // Total est rempli des cartes clan par son constructeur par d�faut
    creerJoueurs(Regles::getInstance().getNbJoueurs());

    // Distribution des cartes
    total.Melanger();
    distribuerCartes(Regles::getInstance().getTailleMain());
    frontiere = Frontiere(totalJoueurs);
}

void JeuClassique::finDePartie()
{
    
}

const std::shared_ptr<Joueur> JeuClassique::getGagnant() const
{
    for (const auto& joueur : totalJoueurs) {
        // Si joueur a gagn�
        if (frontiere.joueurAGagne(joueur)) {
            return joueur;
        }
    }

    // Si aucun joueur n'a gagn�
    return nullptr;
}

bool JeuClassique::terminer()
{
    // Si un joueur a gagn� la partie
    if (getGagnant() != nullptr) {
        finDePartie();

        return true;
    }
    else {
        return false;
    }
}


bool JeuClassique::borneEstRevendicableParJoueur(unsigned int index, const shared_ptr<Joueur> joueur) const
{
    if (frontiere.getBorne(index).estRevendicableParJoueur(joueur)) {
        return true;
    }
    else {
        return false;
    }
}

void JeuClassique::revendiquerBorne(unsigned int index, const shared_ptr<Joueur>& joueur)
{
    frontiere.revendiquerBorne(index, joueur);
}

void JeuClassique::piocher(shared_ptr<Joueur>& joueur)
{
    // Si la main du joueur est pleine
    if (joueur.get()->getMain().GetSizeTas() == Regles::getInstance().getTailleMain()) {
        throw runtime_error("Vous essayez de piocher alors que la main du joueur est pleine");
    }
    // Sinon si la pioche est vide
    else if (pioche.GetSizeTas() == 0) {
        throw runtime_error("Vous essayez de piocher alors que la pioche est vide");
    }
    else {
        joueur.get()->Piocher(pioche);
        //afficher carte pioch�e
    }
}

void JeuClassique::poserCarte(unsigned int indexBorne, unsigned int indexCarte, shared_ptr<Joueur>& joueur)
{
    frontiere.poserCarte(indexBorne, indexCarte, joueur);
}

void JeuClassique::jouerTour(shared_ptr<Joueur>& joueur)
{
    unsigned int indexBorne;
    unsigned int indexCarte;


    // Choix de la borne puis de la carte � y poser
    indexBorne = Interaction::choisirBorne(*this, joueur); // Les verifs sont faites dans choisirBorne
    indexCarte = Interaction::choisirCarte(joueur); // Les verifs sont faites dans choisirCarte

    // Pose de la carte
    poserCarte(indexBorne, indexCarte, joueur);

    // Revendication de borne(s)
    if (Interaction::joueurVeutRevendiquer()) { // Si le joueur veut revendiquer une ou plusieurs bornes
         bool arreter = false;
         while (!arreter) { // On redemande si la borne n'est pas revendicable, si elle l'est on la revendique et on redemande quand m�me
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

    // Si la pioche et la main du joueur ne sont pas vides
    if (pioche.GetSizeTas() != 0 && joueur.get()->getMain().GetSizeTas() != 0) {
        piocher(joueur);
    }

    // Fin du tour
}
