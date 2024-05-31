#include <iostream>
#include "CarteClan.h"
#include "CarteTactique.h"
using namespace std;

int main()
{
    CarteClan carteClanTest(5,"bleu");
    carteClanTest.toString();

    CarteTactique carteTactiqueTest("fou", "detruit tous le plateau");
    carteTactiqueTest.toString();
}
