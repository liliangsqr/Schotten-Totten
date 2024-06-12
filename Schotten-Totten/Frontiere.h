#ifndef FRONTIERE_H
#define FRONTIERE_H
#include "Borne.h"
#include <vector>


class Frontiere
{
private :
    std::vector<Borne> bornes;
public:
    Frontiere():bornes(9){;}
    const Borne& getBorne(int index) const;
    int getNombreDeBornesRevendiquablesParJoueur1() const;
    int getNombreDeBornesRevendiquablesParJoueur2() const;
	
};

#endif FRONTIERE_H



