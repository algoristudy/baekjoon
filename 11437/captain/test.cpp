#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    for (int i = 0; i < 20; i++) {
        cout << "index : " << i << ", value : " << floor(log2(i)) << endl;
    }
    int m = 20;
    while (m--) {
        cout << m << endl;
    }
    cout << pow(2, 4) << endl;
    return 0;
}