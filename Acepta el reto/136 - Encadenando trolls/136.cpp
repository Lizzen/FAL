#include <iostream>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
int eslabon(const int n, const int m) {
    int r = 0, fuerza = n * 2, corte = 0;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    if (fuerza >= m) {
        return 0;
    }
    else {
        corte = m / 3;
        r = m - corte;
    }

    return eslabon(n, corte) + eslabon(n, r) + 1;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n, m;
    cin >> n;
    if (n == 0)
        return false;

    cin >> m;

    // compute solution
    int r = eslabon(n, m);

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