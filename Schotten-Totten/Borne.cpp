#include "Borne.h"

void Borne::AjouterCarte(int joueur, unique_ptr<Carte>&& carte) {
    if(joueur==1){
        CarteJ1.Ajouter(move(carte));
    } else if (joueur ==2){
        CarteJ2.Ajouter(move(carte));
    }
}

