#include <iostream>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
int papel(const int n, const int m) {
    int r = false;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i

    if (n < 10 || m < 10) {
        return 0;
    }
    else if (n > m) {
        r = n / m;
        r += papel(n - m * r, m);
    }
    else {
        r = m / n;
        r += papel(n, m - n * r);
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

    cin >> m;

    // compute solution
    int r = papel(n, m);
    // write solution
    cout << r << '\n';

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (solve());

    return 0;
}