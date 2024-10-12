#include <iostream>
#include <vector>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
int sum(const vector<int>& v) {
    int r = 0, max = 0, min = 1990, i = 0;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
  	while (i < v.size()){
        if (v[i] > max) { max = v[i]; }
        if (v[i] < min) { min = v[i]; }
      	i++;
    }
    r = max - min - i + 1;
    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

void solve() {
    // read case
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution
    int r = sum(v);

    // write solution
    cout << r << "\n";
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
