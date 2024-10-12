#include <iostream>
#include <vector>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
int sum(int x, int n) {
    int r = 0, j = 1, aux = 1;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    if (n > 0) {
        while (j < n + 1) {
            aux = (x * aux) % 1000007;
            r =  (aux + r) % 1000007;
            j++;
        }
    }
    r += 1;
    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int x, n;
    cin >> x;  
    cin >> n;
    // The boolean value of cin indicates if the last read was successful
    // (you need to read something before checking it!) 
    if (!cin)
        return false;

    // compute solution
    int r = sum(x, n);
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