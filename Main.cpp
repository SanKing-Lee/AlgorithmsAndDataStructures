#include "Sort.h"
#include "Graph.h"

extern void TestGraphTraverse();
extern void TestGraphTopSort();
extern void TestSSSP();

int main(){
    // cout << "Test GraphTraverse: \n";
    // TestGraphTraverse();
    // cout << "Test GraphTopSort: \n";
    // TestGraphTopSort();
    cout << "Test SSSP: \n";
    TestSSSP();
    return 0;
}