#include "Total.h"

Total::Total()
{
    for (auto& itCoul : ENUMCOULEURS) {
        for (auto& itVal ENUMVALEURS) {
            Ajouter(make_unique<Carte(itVal, itCoul)>);
        }
    }
}
