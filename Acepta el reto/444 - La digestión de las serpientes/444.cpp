#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
int intervalo(const vector<int>& v, int m) {
    int r = 0, cont = 0, unos = 0, cero = m;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 1) {
            ++unos;
            ++cont;
            cero = m;
        }
        else if (v[i] == 0 && unos > 0) {
            --cero;
            ++cont;
        }

        if (v[i] == 1 && unos > 1 && cont > r) {
            r = cont;
        }
        else if (v[i] == 0 && cero < 0) {
            cont = 0;   
            unos = 0;
        }
        
        if (unos > 0 && r == 0) {
            r = 1;
        }

    }
    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n, m;
    cin >> n;
    cin >> m;
    if (n == 0)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution
    int r = intervalo(v, m);

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