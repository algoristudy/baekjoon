#include <cstdio>
#include <iostream>
#include <string>
#include <typeinfo>       // operator typeid

using namespace std;

int const MAX_KNIGHT = 40 * 26;

struct pos {
    char x;
    char y;
};

int N, M;
pos king, knight[MAX_KNIGHT];

int main() {
    char x[3] = "-1";
    cout << x[0] << endl;
    char a[3] = "A";
    cout << a[0] << endl;
    cout << typeid(a[0]).name() << endl;
    cout << typeid(a[0] - 'A').name() << endl;
    cout << x[0] << endl;
    string str = "A";
    int y = atoi(str.c_str()) + 1;
    cout << y << endl;

    return 0;
}