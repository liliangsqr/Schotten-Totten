#include <iostream>
#include "CarteClan.h"
#include "CarteTactique.h"
#include "vector"
#include "Total.h"
#include "TotalClassique.h"
#include "TotalTactique.h"
using namespace std;

int main()
{
    CarteClan carteClanTest(5,"bleu");
    carteClanTest.toString();

    CarteTactique carteTactiqueTest("Fou","Noire", "detruit tous le plateau");
    carteTactiqueTest.toString();

}
