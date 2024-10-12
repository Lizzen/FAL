#include <iostream>
#include <vector>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
string estado(int n, int m) {
    string r;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    if (n < m) {r = "SENIL";}
    else { r = "CUERDO"; }
    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n, m;
    cin >> n;
    cin >> m;
    if (n == 0 && m == 0)
        return false;

    // compute solution
    string r = estado(n, m);

    // write solution
    cout << r << "\n";

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    while (solve());

    return 0;
}