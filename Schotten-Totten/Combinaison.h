//
// Created by Mac on 9/6/2024.
//



#include <vector>
#include <algorithm>
#include "CarteClan.h"
#include "Carte.h"
#include "Enum.h"
#include "CombinaisonType.h"


class Combinaison{
private:
    std::vector<CarteClan> cartes;
   static bool comparerCartes(const CarteClan& a, const CarteClan& b);

    bool estSuiteDeCouleur() const ;

    bool estBrelan() const;


    bool estCouleur() const ;

    bool estSuite() const ;


    bool estSomme() const ;
public:
    void ajouterCarte(const CarteClan& carte);

    CombinaisonType getMeilleureCombinaison() const ;
};

