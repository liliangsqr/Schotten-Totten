#ifndef FRONTIERE_H
#define FRONTIERE_H

#include <vector>
#include <string>
#include <algorithm>
#include "Borne.h"
#include "Regles.h"

// Repr�sente la fronti�re du jeu contenant toutes les bornes, � initialiser avec le constructeur prenant en param�tres la liste des joueurs
class Frontiere
{
private:
    std::vector<Borne> bornes;

public:
    Frontiere() : bornes(Regles::getInstance().getNbBornes()) { }

    // Cr�e toutes les bornes puis les initialise
    Frontiere(vector<shared_ptr<Joueur>> joueurs);

    // Revendique la borne � la position index si les conditions sont remplies
    void revendiquerBorne(unsigned int index, const shared_ptr<Joueur>& joueur);

    // Renvoie true si le joueur a renvendiqu� n bornes adjacentes ou bien plus de la moiti� des bornes au total
    bool joueurAGagne(const shared_ptr<Joueur>& joueur) const;

    // D�place la carte de la position indexCarte de la main du joueur vers le tasBorne associ� au joueur sur la borne num�ro indexBorne
    void poserCarte(unsigned int indexBorne, unsigned int indexCarte, shared_ptr<Joueur>& joueur);

    const Borne& getBorne(unsigned int index) const {
        if (index < 0 || index >= bornes.size()) {
            throw std::out_of_range("Index de borne invalide");
        }
        return bornes[index];
    }


};

#endif // FRONTIERE_H
