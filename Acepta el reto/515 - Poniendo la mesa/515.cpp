#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
int copas(int n) {
    int r = 0;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i

    if (n == 1) {
        return ++r;
    }
    else if (n == 2) {
        return r + 2;
    }
    else if (n < 1) {
        return r;
    }
    else {
        r += 2;
    }

    if (n % 2 == 0) {
        n -= 2;
        r += copas(n);
    }
    else {
        n -= 3;
        r += copas(n);
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

    // compute solution
    int r = copas(n);
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