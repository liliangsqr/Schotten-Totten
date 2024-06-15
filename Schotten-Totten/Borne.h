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
#include "OnTop.h"
#include "Regles.h"

using namespace std;

class Borne {
private:
    // Joueur propriétaire de la borne
    shared_ptr<Joueur> joueurProprietaire;

    // Accueille les cartes Mode Combat
    OnTop onTop;

    // Associe le nom d'un joueur à son tas de cartes sur la borne
    map<string, TasBorne> tasJoueurs;

    // Renvoie true si tous les TasBorne sont pleins, false sinon
    bool tasSontTousPleins() const;

public:

    Borne() : joueurProprietaire(nullptr) { }

    /*
    string GetInfo() const {
        string info = "Borne Info:\n";
        info += "OnTop size: " + to_string(OnTop.GetSizeTas()) + "\n";
        for (const auto& [nomJoueur, tas] : tasJoueurs) {
            info += "Joueur " + nomJoueur + " size: " + to_string(tas.GetSizeTas()) + "\n";
        }
        return info;
    }
    */

    // Ajoute le nom d'un joueur ainsi que son TasBorne à la borne
    void AjouterJoueur(const string& nomJoueur, TasBorne&& tasBorne) {
        tasJoueurs[nomJoueur] = move(tasBorne);
    }

    // Ajoute une carte au TasBorne du joueur précisé
    void AjouterCarteTasBorne(const Joueur& joueur, unique_ptr<Carte>&& carte) {
        tasJoueurs[joueur.getNom()].Ajouter(std::move(carte));
    }

    // Ajoute une carte ModeCombat sur la borne
    void AjouterCarteOnTop(unique_ptr<ModeCombat>&& carte) {
        onTop.Ajouter(move(carte));
    }

    // TODO : même si tas adversaire pas plein prouver que victoire dans tous les cas
    bool estRevendicableParJoueur(const std::string& nomJoueur) const;

    // Rend joueur propriétaire de la borne
    void reclamer(shared_ptr<Joueur> joueur) {
        joueurProprietaire = joueur;
    }

    const TasBorne& getTasBorne(const string& nomJoueur) const {
        return tasJoueurs.at(nomJoueur);
    }

    shared_ptr<Joueur> getProprietaire() const {
        return joueurProprietaire;
    }
};

#endif // BORNE_H
