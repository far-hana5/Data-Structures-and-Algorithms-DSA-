#include <iostream>
using namespace std;

int main() {
    char X;
    cin >> X;

    if (X >= '0' && X <= '9') {
        cout << "IS DIGIT" << endl;
    } else {
        cout << "ALPHA" << endl;
        if (X >= 'A' && X <= 'Z') {
            cout << "IS CAPITAL" << endl;
        } else {
            cout << "IS SMALL" << endl;
        }
    }

    return 0;
}
