/*
300 11
1200 1250 1350 1400 1300 1600 1600 1600 1700 1500 1300
300 10
1200 1250 1350 1400 1550 1550 1550 1700 1500 1300
0 4
10 10 10 10
*/

#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
bool cota(const vector<int>& v, int min) {
    bool r = true;
    int menor = v[0];
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] <= v[i - 1]) {
            menor = v[i];
        }     
        else if (v[i] - menor > min) {
            r = false;
        }
    }
        
    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n, min;
    cin >> min;
    cin >> n;
    // The boolean value of cin indicates if the last read was successful
    // (you need to read something before checking it!) 
    if (!cin)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution
    bool r = cota(v, min);

    // write solution
    if (r) {
        cout << "APTA" << '\n';
    }
    else {
        cout << "NO APTA" << '\n';
    }
   
    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    while (solve());

    return 0;
}