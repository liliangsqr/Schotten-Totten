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
    TasDeCartes<ModeCombat> OnTop;
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

    void AjouterJoueur(const string& nomJoueur, const TasBorne& tasBorne) {
        tasJoueurs[nomJoueur] = tasBorne;
    }

    const TasBorne& getTasBorne(const string& nomJoueur) const {
        return tasJoueurs.at(nomJoueur);
    }

    void AjouterCarte(const Joueur& joueur, unique_ptr<Carte>&& carte) {
        tasJoueurs[joueur.getNom()].Ajouter(std::move(carte));
    }

    // Modification possible de la méthode estRevendiquableParJoueur
    bool estRevendiquableParJoueur(const std::string& nomJoueur) const {
        Combinaison combinaisonJ;
        for (const auto& carte : tasJoueurs.at(nomJoueur).getCartes()) {
            combinaisonJ.ajouterCarte(*carte);
        }
        return combinaisonJ.getMeilleureCombinaison() != CombinaisonType::Aucune;
    }

};

#endif // BORNE_H
