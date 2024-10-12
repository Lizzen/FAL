#include <iostream>
#include <vector>
#include <ctime> 

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
int sum(const vector<int>& v, int m) {
    int i = 0, j = 0, max = 1;

    while (i < v.size()) {
        if (v[i] - v[j] >= m) {
            ++j;
        }
        else if (v[i] - v[j] < m) {
            ++i;
        }

        if (max < i - j) {
            max = i - j;
        }
    }

    return max;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n, m;
    cin >> n;
    if (n == 0)
        return false;

    cin >> m;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution
    int r = sum(v, m);

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