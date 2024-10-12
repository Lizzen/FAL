#include <iostream>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
int notacion(char n) {
    int r = 0, a = 0, b = 0;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    cin >> n;

    if (n == '+') {
        a = notacion(n);
        b = notacion(n);
        r = a + b;

    }
    else if (n == '-') {
        a = notacion(n);
        b = notacion(n);
        r = a - b;
    }
    else if (n == '*') {
        a = notacion(n);
        b = notacion(n);
        r = a * b;
    }
    else if (n == '/') {
        a = notacion(n);
        b = notacion(n);
        r = a / b;
    }
    else {
        r = n - '0';
    }

    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

void solve() {
    // read case
    char n = ' ';

    // compute solution
    int r = notacion(n);

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
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve();

    return 0;
}