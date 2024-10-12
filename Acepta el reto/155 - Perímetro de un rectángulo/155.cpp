/*
 * THE INPUT ENDS BECAUSE WE REACH THE END OF THE FILE
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
 *
 * 5
 * 1 2 3 4 5
 * 4
 * -2 7 0 -4
 * 1
 * 10
 *
 * Output:
 * ------
 * The program will write the sum of each sequence in a different line.
 *
 * 15
 * 1
 * 10
 *
 * Note: to test the program from the console, you can send the end of file (EoF) character
 * using Ctrl + Z in Windows, or Ctrl + D in Linux or Mac.
 */

#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    int n, m;
    cin >> n >> m;
    // The boolean value of cin indicates if the last read was successful
    // (you need to read something before checking it!) 
    if (n < 0 || m < 0)
        return false;

    // compute solution

    // write solution
    cout << 2*(n+m) << '\n';

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (solve());

    return 0;
}