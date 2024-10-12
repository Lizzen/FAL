#include <iostream>
#include <vector>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
int bolsa(const int n, const string cadena) {
    int r = 0, suma = 0, pos = 0, j = cadena.size() - 1;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i

    int i = cadena.size() - 1;
    while (i >= 0) {
        pos = cadena[i] - '0';
        if (suma == n) {
            ++r;
            suma -= pos;
            --i;
        }
        else if (j >= 0 && suma < n) {
            suma += cadena[j] - '0';
            --j;
        }
        else {
            suma -= pos;
            --i;
        }
    }

    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

void solve() {
    // read case
    int n;
    string cadena;
    cin >> n;
    cin >> cadena;
    // compute solution
    int r = bolsa(n, cadena);

    // write solution
    cout << r << '\n';
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        solve();

    return 0;