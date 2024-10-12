#include <iostream>
#include <vector>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
bool sabe(int ini, int fin, const int n, const int k) {
    int p, iniaux = ini;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i

    for (int i = 0; i < k; ++i) {
        cin >> p;
        if (p > ini && p <= fin) {
            if (p > n && p <= fin) {
                fin = p - 1;
            }
            else if (p <= n && p > ini) {
                ini = p;
            }
        }
    }

    if (fin == ini) {
        return true;
    }
    else {
        return false;
    }
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int ini, fin, n, k;
    cin >> ini >> fin >> n;
    if (ini == 0)
        return false;
    cin >> k;

    // compute solution
    bool r = sabe(ini, fin, n, k);

    // write solution
    if (r) {
        cout << "LO SABE" << '\n';
    }
    else {
        cout << "NO LO SABE" << '\n';
    }


    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    while (solve());

    return 0;
}