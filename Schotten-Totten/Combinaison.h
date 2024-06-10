//
// Created by Mac on 9/6/2024.
//



#include <vector>
#include <algorithm>
#include "CarteClan.h"
#include "Carte.h"
#include "Enum.h"
#include "CombinaisonType.h"


class CombinaisonCartes{
private:
    std::vector<CarteClan> cartes;

    bool estSuiteDeCouleur() ;

    bool estBrelan() ;


    bool estCouleur() ;

    bool estSuite() ;


    bool estSomme() ;
public:
    void ajouterCarte(const CarteClan &carte) ;

    CombinaisonType getMeilleureCombinaison() ;
};

