#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
long long int elevame(const int n, const int m) {
    long long int r = 0;
    
    if (m == 0) {
        return 1;
    }
    else {
        r = elevame(n, m/2);
        if (m % 2 == 0) {
            return (r * r) % 31543; // ej: x^20 = x^10 * x^10
        }
        else {
            return (r * r * n) % 31543; // ej: x^21 = x^10 * x^10 * x
        }
    }
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
        return false;

    // compute solution
    int r = elevame(n, m);

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