#include <iostream>
#include <string>
#include "LCS.h"

using namespace std;

int main() {

    string X = "ABCBDAB";
    string Y = "BDCABA";

    cout << "Sequence X: " << X << endl;
    cout << "Sequence Y: " << Y << endl;

    solveLCS(X, Y);

    return 0;
}