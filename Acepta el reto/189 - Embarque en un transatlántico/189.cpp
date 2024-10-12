#include <iostream>
#include <vector>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
int embarque(vector<int>& v, int m, int& size) {
    int r = 0, i = 0, j = 1;

    while (j < size && i < size) {
        if (v[i] == m) {
            if (v[j] != m && j > i) {
                swap(v[i], v[j]);
                ++i;
                ++j;
            }
            else {
                ++j;
            }
            /*++r;
            v[i] = v[j];
            v[j] = m;
            i = j;
            ++j;*/
        }
        else {
            ++i;
        }
    }
    /*size -= r;*/
    return i;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n, m, a;
    string accion;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cin >> m;
    int r;
    int size = v.size();
    for (int i = 0; i < m; ++i) {
        cin >> accion;
        cin >> a;       // Variable de la accion
        if (accion == "EMBARQUE") {
            r = embarque(v, a, size);
            cout << r << "\n";
            size = r;
        }
        else {
            cout << v[a - 1] << "\n";
        }
    }
    cout << "*" << '\n';

    // compute solution


    // write solution


    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());


    while (solve());

    return 0;
}