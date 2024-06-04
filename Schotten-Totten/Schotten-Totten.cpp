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
    CarteClan carteClanTest(5,5);
    carteClanTest.toString();

    CarteTactique carteTactiqueTest(0,0,0);
    carteTactiqueTest.toString();

}
