#include <iostream>
#include <vector>

 // uncomment to read from a file instead of standard input
 //#include <fstream>

using namespace std;

// Pre: c > 0 && forall k: 0 <= k < v.size() : v[k] >= 0
bool ctramo(const vector<int>& v, const int c) {
    int suma = 0, init = 0;
    bool ret = false;
    // Inv: 0 <= i < v.size() and
    //      suma = Sum k: i <= k < v.size(): v[k] and
    //      ret = Exists k1, k2: 0 <= k1 <= k2 < i: es_ctramo(v, k1, k2, c)
    // Cota: v.size() - i 
    /*for (int i = 0; i < v.size(); ++i) {
        suma += v[i];

        while (suma > c) {
            suma -= v[init];
            ++init;
        }

        if (suma == c) {
            return true;
        }
    }*/

    while (i < v.size() && !ret) {
        suma += v[i];

        //Inv: 0 <= init < v.size() and 
        //      suma = Sum k: init < k < i: v[k]
        //      T: 0 <= init < v.size() 
        while (suma > c) {
            suma -= v[init];
            ++init;
        }

        if (suma == c) {
            ret = true;
        }
    }

    return ret;
}
// Pos: ret = Exist k1, k2: 0 <= k1 <= k2 < v.size(): es_tramo(v, k1, k2, c)
// siendo
// es_tramo(v, k1, k2, c) =  (Sum k: k1 <= k <= k2 : v[k]) == c 
// Coste O(n): Donde n es el número de elementos del vector ya que en el peor de los casos se recorrerá dos veces como máximo el vector.

bool solve() {
    // read case
    int n, m, c;
    cin >> n;
    if (n <= 0)
        return false;
    
    

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cin >> c;
    // compute solution
    // write solution
    if (ctramo(v, c)) {
        cout << "Si\n";
    }
    else {
        cout << "No\n";
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