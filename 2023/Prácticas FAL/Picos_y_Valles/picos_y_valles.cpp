// David Ferreras Díaz
#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true

// picos: Cantidad de picos existentes
// valles: Cantidad de valles existentes
void picosyvalles(const vector<int>& v, int& picos, int& valles) {
    // Inv: 1 <= i < v.size() and 
    // picos = #k: 1 <= k < i: v[k - 1] < v[k] > v[k + 1] and
    // valles = #j: 1 <= j < i: v[j-1] > v[j] < v[j+1]
    // T: v.size()-1-i

    for (int i = 1; i < v.size() - 1; ++i) {
        // Procesamos picos
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            ++picos;
        }
        // Procesamos valles
        else if (v[i] < v[i - 1] && v[i] < v[i + 1]) {
            ++valles;
        }
    }
}
// Pos: picos = #k: 1 <= k < v.size() -1: v[k - 1] < v[k] > v[k + 1] and
//      valles = #j: 1 <= j < v.size() -1: v[j-1] > v[j] < v[j+1]

void solve() {
    // read case
    int n, picos = 0, valles = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution
    picosyvalles(v, picos, valles);

    // write solution
    cout << picos << " " << valles << "\n";
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve();

    return 0;
}