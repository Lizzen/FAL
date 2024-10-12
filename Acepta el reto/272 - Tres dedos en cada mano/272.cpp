#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
void sum(int n) {
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    
    if (n / 6 < 1) {
        cout << n;
    }
    else {
        sum(n / 6);
        cout << n % 6;
    }
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

void solve() {
    // read case
    int n;
    cin >> n;

    // compute solution
    sum(n);

    // write solution
    cout << '\n';
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve();

    return 0;
}