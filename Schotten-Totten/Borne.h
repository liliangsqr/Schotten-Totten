#include <vector>
#include <algorithm>
#include <map>
#include "Carte.h"
#include <string.h>
#include "TasBorne.h"
#include "ModeCombat.h"

using namespace std ;

class Borne {
private:
    TasDeCartes<ModeCombat> OnTop;
    TasBorne CarteJ1;
    TasBorne CarteJ2;

public:

    Borne() = default;

    string GetInfo() const {
        string info = "Borne Info:\n";
        info += "OnTop size: " + to_string(OnTop.GetSizeTas()) + "\n";
        info += "CarteJ1 size: " + to_string(CarteJ1.GetSize()) + "\n";
        info += "CarteJ2 size: " + to_string(CarteJ2.GetSize()) + "\n";
        return info;
    }
};



