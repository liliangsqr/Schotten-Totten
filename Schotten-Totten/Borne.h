



#include <vector>
#include <algorithm>
#include <map>
#include "Carte.h"
#include "CarteClan.h"
#include "string.h"
#include "CarteTactique.h"
using namespace std ;

class Borne {
private:
    TasBorne CarteJ1 ;
    TasBorne CarteJ2 ;

public:
    void AjouterCarte(int joueur,unique_ptr<Carte>carte);
    bool EstSuiteDeCouleur(const vector<unique_ptr<Carte>>& cartes);
    bool EstBrelan(const vector<unique_ptr<Carte>>& cartes);
    bool EstCouleur(const vector<unique_ptr<Carte>>& cartes);
    bool EstSuite(const vector<unique_ptr<Carte>>& cartes);
    int Somme(const vector<unique_ptr<Carte>>& cartes);
};



