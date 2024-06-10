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

using namespace std ;

class Borne {
    // Attributs
private:
    TasDeCartes<ModeCombat> OnTop;
    TasBorne CarteJ1;
    TasBorne CarteJ2;

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
    const TasBorne& getTasBorneJ1() const{
        return CarteJ1;
    }
    const TasBorne& getTasBorneJ2() const{
        return CarteJ2;
    }

    void AjouterCarte(int joueur, unique_ptr<Carte>&& carte);
    bool estRevendiquableParJoueur1() const;
    bool estRevendiquableParJoueur2() const;


};

#endif