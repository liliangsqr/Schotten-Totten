#include <iostream>
#include "CarteClan.h"
#include "CarteTactique.h"
#include "vector"
using namespace std;

int main()
{
    CarteClan carteClanTest(5,"bleu");
    carteClanTest.toString();

    CarteTactique carteTactiqueTest("Fou","Noire", "detruit tous le plateau");
    carteTactiqueTest.toString();

}
