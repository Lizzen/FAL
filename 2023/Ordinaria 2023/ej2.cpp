#include <iostream>
#include <vector>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// v es el vector siempre ordenado
// init es el inicio del trozo del vector escogido
// fin es el final del trozo del vector escogido
bool nifunifa(const vector<int>& v, int init, int fin) {
    if (fin - init < 2 || v[init] == v[fin]) {
        return false;
    }
    int medio = (init + fin) / 2;
    
    if (v[medio] == v[fin]) {
        return (nifunifa(v, init, medio));
    }
    else if (v[medio] == v[init]) {
        return (nifunifa(v, medio, fin));
    }
    else {
        return true;
    }
}
// Coste (sea n = b-a+1):
// T(n) = c0 si n <= 2
// T(n) = T(n/2) si n > 2
// luego a = 1, b = 2 y k = 0 -> O(log n)

bool solve() {
    // read case
    int n;
    cin >> n;
    if (n <= 0)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution
    // write solution
    if (nifunifa(v, 0, n - 1)) {
        cout << "Si\n";
    }
    else {
        cout << "No\n";
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