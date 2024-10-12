#include <iostream>
#include <vector>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
string sum(string n) {
    string r = "";
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    if (n.size() != 1){
        for (int i = 0; i < n.size()-1; ++i) {
            r += n[i];
            r += "0";
        }
        r += n[n.size() - 1];
    }
    else { r = n; }
    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    string n;
    cin >> n;
    // The boolean value of cin indicates if the last read was successful
    // (you need to read something before checking it!) 
    if (!cin)
        return false;


    // compute solution
    string r = sum(n);

    // write solution
    cout << r << endl;

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    while (solve());

    return 0;
}