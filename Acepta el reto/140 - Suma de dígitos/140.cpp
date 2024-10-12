#include <iostream>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
int sum(const string n, int size) {
    int r = 0;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    if (size == 0) {
        cout << n[size];
        r = n[size] - 48 + sum(n, ++size);
    }
    else if (size < n.size()) {
        cout << " + " << n[size];
        r = n[size] - 48 + sum(n, ++size);
    }
    else {
        cout << " = ";
    }

    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    string n;
    std::cin >> n;
    if (n < "0")
        return false;

    // compute solution
    int r = sum(n, 0);

    // write solution

    cout << r << '\n';

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    while (solve());

    return 0;
}