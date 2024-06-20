#include <iostream>
#include "CarteClan.h"
#include "CarteTactique.h"
#include "vector"
#include "Total.h"
#include "TotalClassique.h"
#include "TotalTactique.h"
#include "Affichage.h"
#include "JeuClassique.h"
#include "Application.h"

using namespace std;

int main()
{
    try {
        Application a;
        a.lancerApplication();
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

}
