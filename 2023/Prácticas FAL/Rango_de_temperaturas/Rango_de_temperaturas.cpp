// David Ferreras Díaz
#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: a <= b
int temp(const vector<float>& v, const float min, const float max) {
    int r = 0;
    // Inv: 0 <= i <= v.size() and r = #k: 0 <= k < i: min <= v[k] <= max
    // T: v.size()-i
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] >= min && v[i] <= max) {
            ++r;
        }
    }

    return r;
}
// Pos: r = #k: 0 <= k < v.size(): min <= v[k] <= max
// Coste O(n): Donde n es v.size() ya que se tiene que recorrer todo el vector siempre.

bool solve() {
    // read case
    int n;
    float min, max;
    cin >> n;
    if (n == -1)
        return false;
    cin >> min >> max;
    vector<float> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute solution and write solution
    cout << temp(v, min, max) << endl;

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    while (solve());

    return 0;
}