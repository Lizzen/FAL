#include <iostream>
#include <string>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
bool polidivisible(const long long int n, const int indice) {
    bool r = false;
    // Inv: 0 <= i <= n and r = Sum k: 0 <= k < i: v[k]
    // T: v.size()-i
    
    if (indice == 1) {
        return true;
    }
    else if (n % indice == 0) {
        r = polidivisible(n/10, indice - 1);
    }

    return r;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    long long int n, indice = 0;
    string aux;
    cin >> n;
    // The boolean value of cin indicates if the last read was successful
    // (you need to read something before checking it!) 
    if (!cin)
        return false;

    aux = to_string(n);

    // compute solution
    bool r = polidivisible(n, aux.size());
    // write solution
    if (r) {cout << "POLIDIVISIBLE" << '\n';}
    else {cout << "NO POLIDIVISIBLE" << '\n'; }

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    while (solve());

    return 0;
}