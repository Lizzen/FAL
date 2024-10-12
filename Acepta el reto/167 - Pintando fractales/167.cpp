#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
int fractal(const int n,  const int m) {
    int r = 0;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    if (n > 0) {
        r += n * m;
        r += fractal(n / 2, m * 4);
    }
    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n , m = 4;
    cin >> n;
    // The boolean value of cin indicates if the last read was successful
    // (you need to read something before checking it!) 
    if (!cin)
        return false;

    // compute solution
    int r = fractal(n, m);

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