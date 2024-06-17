#ifndef REGLE_H
#define REGLE_H
#include <vector>
#include <string>

using namespace std;

// Singleton contenant toutes les constantes liées aux règles du jeu
class Regles
{
private:
    unsigned int nbJoueurs;
    vector<string> modesJeu;
    unsigned int capaciteMaxTasBorne;
    unsigned int nbBornes;
    unsigned int nbBornesAdjacentesPourGagner;
    unsigned int tailleMain;
    size_t tailleMinCombinaison;

    // Constructeur en privé
    Regles() : nbJoueurs(2), modesJeu({ (string)"Classique", (string)"Tactique" }), capaciteMaxTasBorne(3), nbBornes(9), nbBornesAdjacentesPourGagner(3), tailleMain(6), tailleMinCombinaison(2) { }

    // Suppression des constructeur de copie et opérateur d'assignation
    Regles(const Regles&) = delete;
    void operator=(const Regles&) = delete;

public:
    // Méthode pour accéder à l'instance unique
    static Regles& getInstance() {
        static Regles instance; // Instance unique créée au premier appel
        return instance;
    }

    // Getters
    const vector<string>& getModesJeu() const { return modesJeu; }
    unsigned int getNbJoueurs() const { return nbJoueurs; }
    unsigned int getCapaciteMaxTasBorne() const { return capaciteMaxTasBorne; }
    unsigned int getNbBornes() const { return nbBornes; }
    unsigned int getNbBornesAdjacentesPourGagner() const { return nbBornesAdjacentesPourGagner; }
    unsigned int getTailleMain() const { return tailleMain; }
    size_t getTailleMinCombinaison() const { return tailleMinCombinaison; }
};

#endif // !REGLE_H
