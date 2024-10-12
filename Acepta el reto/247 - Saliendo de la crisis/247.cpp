#include <iostream>
#include <vector>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
string sum(const vector<int>& v) {
    string r = "SI";
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i

    int i = 0;

    while (r == "SI" && i < v.size()-1){
        if (v[i] >= v[i+1]) {
            r = "NO";
        }
        ++i;
    }
    
    return r;
}
// Pos: r = true k: 0 <= k < v.size(): v[k] < v[k+1]

bool solve() {
    // read case
    int n = 0;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // compute solution
    string r = sum(v);

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