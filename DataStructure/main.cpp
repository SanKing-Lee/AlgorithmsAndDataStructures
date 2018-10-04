#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    AList<int> al;
    al.append(1);
    al.append(2);
    al.append(3);
    al.append(9);
    al.moveToPos(2);
    al.insert(5);
    al.moveToStart();
    al.remove();
    al.moveToEnd();
    al.prev();
    al.remove();
    for(al.moveToStart(); al.currPos()<al.length(); al.next()){
        cout << al.getValue() << " ";
    }
    cout << endl;
    return 0;
}
