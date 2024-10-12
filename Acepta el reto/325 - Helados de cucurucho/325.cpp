#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: true
void helado(int chocolate, int vainilla, string solParcial, string &sol) {
    if (chocolate == 0 && vainilla == 0) { // is solution
        sol.append(solParcial + " ");
    }
    else {
        if (chocolate > 0) {
            helado(chocolate - 1,vainilla, solParcial + "C", sol);
        }

        if (vainilla > 0) {
            helado(chocolate, vainilla - 1, solParcial + "V", sol);
        }
    }

}

void solve() {
    // read case
    int n, m;
    string solParcial, sol;
    cin >> n >> m;

    // compute solution
    helado(n, m, solParcial, sol);
    sol.pop_back();
    // write solution
    cout << sol << '\n';
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
