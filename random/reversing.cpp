#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int A[1000]; // Max value of N is 1000

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        cout << A[i] << " ";
    }

    cout << endl;
    return 0;
}
