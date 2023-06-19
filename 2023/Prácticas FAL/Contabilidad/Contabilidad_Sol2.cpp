/*
 * THE INPUT CONTAINS A MARKER TO INDICATE THERE ARE NO MORE TEST CASES
 * -----------------------------------------------------------------------------
 *
 * Given a nonempty sequence of integer of length less than or equal to
 * 1000, calculate the sum of all of them.
 *
 * Input:
 * -----
 * Each test case is described in 2 lines. The first line contains a number
 * indicating the length of the sequence. The second line contains the
 * sequence of numbers itself.
 * The last test case contains a sequence of length 0 that should not be processed.
 *
 * 5
 * 1 2 3 4 5
 * 4
 * -2 7 0 -4
 * 1
 * 10
 * 0
 *
 * Output:
 * ------
 * The program will write the sum of each sequence in a different line.
 *
 * 15
 * 1
 * 10
 */

#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
bool contabilidad(const vector<int>& v) {
    bool ret = false;
    // Inv: 0 <= i < v.size() and 
    // ret = Exist k1: 0 <= k1 < i: v[k] = (sum k2: k1 < k2 < i: v[k2])
    // T: v.size()-i
    int i = v.size() - 1, suma = 0;
    while (i >= 0 && v[i] != suma) {
        suma += v[i];
        --i;
    }

    return i >= 0;
}
// Pos: ret = Exist k1: 0 <= k1 < v.size(): v[k] = (sum k2: k1 < k2 < v.size(): v[k2])

bool solve() {
    // read case
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution and write solution
    if (contabilidad(v)) { cout << "YES\n"; }
    else { cout << "NO\n"; }

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    while (solve());

    return 0;
}