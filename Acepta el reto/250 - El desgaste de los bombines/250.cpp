#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
int cambio(const vector<int>& v) {
    int r = 0, total = 0, dif = 0, i = 0, sumaI = v[i], sumaD = 0;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    for (int i = 0; i < v.size(); ++i) {
        total += v[i];
    }
    int min = abs(total);

    while (i < v.size() - 1) {
        sumaD = total - sumaI;
        dif = abs(sumaD) - abs(sumaI);
        dif = abs(dif);

        if (min > dif && dif != total) {
            r = i + 1;
            min = dif;
        }

        ++i;
        sumaI += v[i];
    }
    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n, m;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution
    int r = cambio(v);

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