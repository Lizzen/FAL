#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
int nino(const vector<int>& v) {
    int r = 1, max = v[0], min = v[0];
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > max) {
            max = v[i];
        }
        else if (v[i] <= min) {
            min = max;
            r = i + 1;
        }
    }
    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution
    int r = nino(v);

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