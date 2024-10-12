#include <iostream>
#include <vector>
#include <algorithm>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
long long int peso(vector<int>& v, const int peso) {
    long long int r = 0, i = 0, j = v.size() -1;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    sort(v.begin(), v.end());

    while (i != j) {
        if (v[j] + v[i] <= peso) {
            r += j - i;
            ++i;
        }
        else {
            --j;
        }
    }

    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    int n, m;
    cin >> n;
    if (n == 0)
        return false;

    cin >> m;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution
    long long int r = peso(v, m);

    // write solution
    cout << r << '\n';

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());
    //cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    while (solve());

    return 0;
}