#include <iostream>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

int pi, di, pd, dd, peso;

// Pre: true
bool movil(int pi, const int di, int pd, const int dd, int& peso) {
    bool r = true, l = true;
    int pil = 0, dil = 0, pdr = 0, ddr = 0;

    if (pi == 0 && di == 0 && pd == 0 && dd == 0) {
        return false;
    }

    if (pi == 0) {
        cin >> pil >> dil >> pdr >> ddr;
        l = movil(pil, dil, pdr, ddr, pi);
    }

    if (pd == 0) {
        cin >> pil >> dil >> pdr >> ddr;
        r = movil(pil, dil, pdr, ddr, pd);
    }

    peso = pi + pd;

    return (l && r && (pi * di == pd * dd));
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case

    cin >> pi >> di >> pd >> dd;

    // compute solution
        // write solution
    if (pi == 0 && di == 0 && pd == 0 && dd == 0) {
        return false;
    }


    if (movil(pi, di, pd, dd, peso)) {
        cout << "SI" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
    
    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (solve());

    return 0;
}