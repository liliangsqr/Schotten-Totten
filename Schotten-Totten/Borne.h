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

// Une borne a n (2 de base) tas associés à des joueurs. Elle peut être revendiquée si un joueur a une meilleure combinaison que le/les autres
class Borne {
private:
    // Joueur propriétaire de la borne
    shared_ptr<Joueur> joueurProprietaire;

    // Accueille les cartes Mode Combat
    OnTop onTop;

    // Associe un joueur à son tas de cartes sur la borne
    map<shared_ptr<Joueur>, TasBorne> tasJoueurs;





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
    void ajouterJoueur(shared_ptr<Joueur> joueur, TasBorne&& tasBorne) {
        tasJoueurs[joueur] = move(tasBorne);
    }

    // Ajoute une carte au TasBorne du joueur précisé (prend directement la carte en paramètres)
    void ajouterCarteTasBorne(shared_ptr<Joueur> joueur, unique_ptr<Carte>&& carte) {
        tasJoueurs[joueur].Ajouter(std::move(carte));
    }

    // Ajoute une carte au TasBorne du joueur précisé (prend l'index de la carte dans la main du joueur en paramètres)
    void ajouterCarteTasBorne(shared_ptr<Joueur> joueur, unsigned int indexCarte) {
        joueur.get()->PoserCarte(indexCarte, tasJoueurs[joueur]);
    }

    // Ajoute une carte ModeCombat sur la borne
    void ajouterCarteOnTop(unique_ptr<ModeCombat>&& carte) {
        onTop.Ajouter(move(carte));
    }

    // Renvoie true si le joueur peut réclamer la borne
    // TODO 1 : même si tas adversaire pas plein prouver que victoire dans tous les cas
    // TODO 2 : si mêmes combinaison et somme, choisir joueur arrivé en premier (pour l'instant choix injuste)
    bool estRevendicableParJoueur(shared_ptr<Joueur> joueur) const;

    // Rend joueur propriétaire de la borne /!\ SANS VERIFICATIONS
    void revendiquer(shared_ptr<Joueur> joueur) {
        joueurProprietaire = joueur;
    }





    const TasBorne& getTasBorne(shared_ptr<Joueur> joueur) const {
        return tasJoueurs.at(joueur);
    }

    shared_ptr<Joueur> getProprietaire() const {
        return joueurProprietaire;
    }
};

#endif // BORNE_H
