#include <iostream>
#include <vector>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
long long int mult(const vector<float>& v) {
    long long int r = 0, s = 0, n = 0, cero = 0;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > 1) {
            ++s;
        }
        else if (v[i] == 0 || v[i] == 1)
        {
            r += v.size() - 1 - cero;
            ++cero;
        }
        else {
            ++n;
        }
    }



    r += (s * (s - 1) / 2) + (n * (n - 1) / 2);

    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<float> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution
    long long int r = mult(v);

    // write solution
    cout << r << '\n';

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (solve());

    return 0;
}