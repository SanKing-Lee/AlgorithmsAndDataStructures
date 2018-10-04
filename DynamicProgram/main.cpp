#include <iostream>
#include "DynamicProgram.h"

using namespace std;

int main()
{
    CutRod cr;
    cr.Init();
    cout << "The most price: " << cr.RecurssiveCutRod(Length) << endl;
    return 0;
}
