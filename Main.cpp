#include "Sort.h"
#include "Graph.h"

extern void TestGraphTraverse();
extern void TestGraphTopSort();
extern void TestSSSP();
extern void TestMST();

int main(){
    // cout << "Test GraphTraverse: \n";
    // TestGraphTraverse();
    // cout << "Test GraphTopSort: \n";
    // TestGraphTopSort();
    // cout << "Test SSSP: \n";
    // TestSSSP();
    cout << "Test MST: \n";
    TestMST();
    return 0;
}