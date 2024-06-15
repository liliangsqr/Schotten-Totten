#ifndef REGLE_H
#define REGLE_H
#include <vector>
#include <string>

using namespace std;

class Regles
{
private:
    unsigned int pNbJoueur;
    vector<string> pModesJeu;
    unsigned int capaciteMaxTasBorne;
    unsigned int nbBornes;
    unsigned int nbBornesAdjacentesPourGagner;

    // Constructeur en privé
    Regles() : pNbJoueur(2), pModesJeu({ "Classique", "Tactique" }), capaciteMaxTasBorne(3), nbBornes(9), nbBornesAdjacentesPourGagner(3) { }

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
    const vector<string>& getModesJeux() const { return pModesJeu; }
    unsigned int getNBjoueurs() const { return pNbJoueur; }
    unsigned int getCapaciteMaxTasBorne() const { return capaciteMaxTasBorne; }
    unsigned int getNbBornes() const { return nbBornes; }
    unsigned int getNbBornesAdjacentesPourGagner() const { return nbBornesAdjacentesPourGagner; }
};

#endif // !REGLE_H
