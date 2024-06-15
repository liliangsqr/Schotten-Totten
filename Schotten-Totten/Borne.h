#ifndef BORNE_H
#define BORNE_H

#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include "Carte.h"
#include "TasBorne.h"
#include "ModeCombat.h"
#include "Combinaison.h"
#include "TasDeCartes.h"
#include "Joueur.h"

using namespace std;

class Borne {
private:
    // Accueille les cartes Mode Combat
    TasDeCartes<ModeCombat> OnTop;

    // Associe le nom d'un joueur à son tas de cartes sur la borne
    map<string, TasBorne> tasJoueurs;

public:

    Borne() = default;

    string GetInfo() const {
        string info = "Borne Info:\n";
        info += "OnTop size: " + to_string(OnTop.GetSizeTas()) + "\n";
        for (const auto& [nomJoueur, tas] : tasJoueurs) {
            info += "Joueur " + nomJoueur + " size: " + to_string(tas.GetSize()) + "\n";
        }
        return info;
    }

    // Ajoute le nom d'un joueur ainsi que son TasBorne à la borne
    void AjouterJoueur(const string& nomJoueur, TasBorne&& tasBorne) {
        tasJoueurs[nomJoueur] = move(tasBorne);
    }


    const TasBorne& getTasBorne(const string& nomJoueur) const {
        return tasJoueurs.at(nomJoueur);
    }

    // Ajoute une carte au TasBorne du joueur précisé
    void AjouterCarte(const Joueur& joueur, unique_ptr<Carte>&& carte) {
        tasJoueurs[joueur.getNom()].Ajouter(std::move(carte));
    }

    // Vérifie si un joueur a une combinaison autre que la somme
    bool estRevendicableParJoueur(const std::string& nomJoueur) const {
        /*
        Combinaison combinaisonJ;
        for (const auto& carte : tasJoueurs.at(nomJoueur).getCartes()) {
            combinaisonJ.ajouterCarte(*carte);
        }
        return combinaisonJ.getMeilleureCombinaison() != CombinaisonType::Aucune;
        */

        bool retCond = true;
        for (const auto& itMap : tasJoueurs) {
            if (itMap.second.GetSizeTas() != )
        }
    }
};

#endif // BORNE_H
