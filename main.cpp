#include "./main/tree.h"
#include <iostream>
using namespace std;

int main() {
    AVL<float, float> a;
    a.insertNode(1.1, 20.0);
    a.insertNode(3.3, 15.6);
    a.insertNode(10.1, 17.8);
    a.printLNR();
    cout << endl;
    a.removeNode(20.0);
    a.printLNR();
    return 0;
}