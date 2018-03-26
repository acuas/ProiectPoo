#include <iostream>
#include "LinkedList.h"
#include "Set.h"

using namespace std;

int main() {
    Set A, B, C;
    cin >> A;
    cin >> B;
    C = A + B;
    C = A - B;
    cout << C;

    return 0;
}