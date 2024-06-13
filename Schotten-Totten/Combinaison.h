

#include <vector>
#include <algorithm>
#include "CarteClan.h"
#include "Carte.h"
#include "Enum.h"
#include "CombinaisonType.h"

using namespace std;


class Combinaison{
private:
    std::vector<Carte> cartes;


    static bool comparerCartes(const Carte& a, const Carte& b);

    bool estSuiteDeCouleur() const ;

    bool estBrelan() const;


    bool estCouleur() const ;

    bool estSuite() const ;


    bool estSomme() const ;
public:

    void ajouterCarte(const Carte& carte);

    CombinaisonType getMeilleureCombinaison() const ;
};

