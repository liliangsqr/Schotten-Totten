#ifndef TASDECARTES_H
#define TASDECARTES_H

#include <vector>
#include <memory>
#include <random> // Pour random_device et mt19937
#include <algorithm> // Pour shuffle
#include "Carte.h"

using namespace std;

template<class T>
class TasDeCartes
{
    protected :
        // Attributs

        vector<unique_ptr<T>> tas;
        unsigned int capacite = 0;

    public :
        // Constructeurs
        
        TasDeCartes(unsigned int cap) : capacite(cap) { }

        // Méthodes

        // Mélange le tas aléatoirement
        void Melanger()
        {
            random_device rd;
            mt19937 g(rd());
            shuffle(tas.begin(), tas.end(), g);
        }

        // Ajoute/move une carte en RVALUE sur le haut du tas
        void Ajouter(unique_ptr<T>&& carte)
        {
            tas.push_back(move(carte));
        }

        // Retourne une référence const vers le T à la position index afin de seulement la consulter
        // Attention on ne doit pas pouvoir faire delete sur l'adresse de la valeur retournée
        const T& operator[](unsigned int index)
        {
            if (index >= tas.size()) {
                throw out_of_range("Index hors limites");
            }
            return *tas[index];
        }

        // Retire une carte du tas et renvoie un unique_ptr à cette carte
        unique_ptr<T> Retirer(unsigned int index)
        {
            if (index >= tas.size()) {
                throw out_of_range("Index hors limites");
            }

            unique_ptr<T> carte = move(tas[index]);
            tas.erase(tas.begin() + index);
            return carte;
        }

        // Get la taille du tas 
        unsigned int GetSizeTas() const {
            return (unsigned int)tas.size();
        }

        const vector<unique_ptr<T>>& getCartes() const {
            return tas;
        }

        unsigned int GetCapacite() { return capacite; }
};

#endif // TASDECARTES_H