#ifndef BORNE_H
#define BORNEH

#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include "Carte.h"
#include "TasBorne.h"
#include "ModeCombat.h"
#include"Combinaison.h"
#include "TasDeCartes.h"
#include "Joueur.h"

using namespace std ;

class Borne {
    // Attributs
private:
    TasDeCartes<ModeCombat> OnTop;

    // Associe, sur une borne, un tas à un Joueur (il peut y avoir n joueurs)
    map<string, TasBorne> tasJoueurs;

    // TasBorne CarteJ1;
    // TasBorne CarteJ2;

public:
    // Constructeurs

    Borne() = default;

    // M�thodes

    string GetInfo() const {
        string info = "Borne Info:\n";
        info += "OnTop size: " + to_string(OnTop.GetSizeTas()) + "\n";
        info += "CarteJ1 size: " + to_string(CarteJ1.GetSize()) + "\n";
        info += "CarteJ2 size: " + to_string(CarteJ2.GetSize()) + "\n";
        return info;
    }

    // Ajouter le joueur et son TasBorne à la map
    void AjouterJoueur(const string& nomJoueur, const TasBorne& tasBorne) {
        tasJoueurs[nomJoueur] = tasBorne;
    }


    const TasBorne& getTasBorne(const string& nomJoueur) const {
        return tasJoueurs.at(nomJoueur); // Récupérer le tasborne associé au joueur
    }

    //ajouter les cartes au tas
    void AjouterCarte(Joueur joueur, unique_ptr<Carte>&& carte);
    bool estRevendiquableParJoueur(Joueur joueur) const;


};

#endif