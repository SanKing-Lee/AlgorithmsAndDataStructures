#include <iostream>
#include <cmath>

using namespace std;

const static int Length = 10;
class CutRod {
private:
    int *Price;

public:
    CutRod() {};
    CutRod(int *p): Price(p) {}
    ~CutRod() {
        delete []Price;
    };
    void Init();
    int RecurssiveCutRod(int n);
    void MemorizedCutRod();
    void ButtomUpCutRod();
};
