#include "DynamicProgram.h"

void CutRod::Init() {
    Price = new int(Length);

    for(int i = 0; i < Length; i++){
        Price[i] = rand()%(1 + i*5);
        cout << Price[i] << " ";
    }
    cout << endl;
}

int CutRod::RecurssiveCutRod(int n) {
    if (n == 0) {
        return 0;
    }
    int q =0;
    for (int i = 1; i <= n; i++){
        q = max(q, Price[i-1] + RecurssiveCutRod(i - 1));
    }
    return q;
}
