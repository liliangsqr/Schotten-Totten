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
    TotalClassique tot = TotalClassique();
    cout << tot.GetTas().size() << endl;
}
