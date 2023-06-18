#include <iostream>
#include <vector>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
void reparto(
    const vector<int>& v,       // Vector de valores de las monedas
    int monedas,                // Monedas minimas para cada pirata
    vector<bool>& sol,    // Vector solución, false = pirata1, true = pirata2
    int& diferencia,            // Diferencia min de monedas 
    int etapa,                  // Siguiente moneda a procesar
    int pcoin1, int pcoin2,     // Número de monedas de cada pirata
    int pval1, int pval2,       // Valor del reparto de cada pirata
    int& num_soluciones         // Distintas combinaciones validas
    ) {

    if (etapa == sol.size()) {
        // Todas las monedas han sido repartidas
        if (pcoin1 >= monedas && pcoin2 >= monedas) {
            // Actualiza los valores
            int dif = abs(pval1 - pval2);
            if (dif < diferencia) {
                // Nueva solución
                diferencia = dif;
                num_soluciones = 1;
            }
            else if (dif == diferencia) {
                // Combinación valida
                ++num_soluciones;
            }
        }
    }
    else {
        // Repartir monedas
        // Se intenta ver si se reparte la moneda al primer pirata, quedarían suficientes monedas para el segundo pirata
        if ((max(monedas - pcoin1 - 1, 0) + max(monedas - pcoin2, 0)) < v.size() - etapa) {
            sol[etapa] = false; // se la queda el pirata 1
            reparto(v, monedas, sol, diferencia, etapa + 1, pcoin1 + 1, pcoin2, pval1 + v[etapa], pval2, num_soluciones);
        }

        // Importante no hacer else if para que se puedan verificar todas las posibles soluciones
        // Se intenta ver si se reparte la moneda al segundo pirata, quedarían suficientes monedas para el segundo pirata
        if ((max(monedas - pcoin1, 0) + max(monedas - pcoin2 - 1, 0)) < v.size() - etapa) {
            sol[etapa] = true; // se la queda el pirata 1
            reparto(v, monedas, sol, diferencia, etapa + 1, pcoin1, pcoin2 + 1, pval1, pval2 + v[etapa], num_soluciones);
        }
    }
}

bool solve() {
    // read case
    int n, monedas;
    cin >> n;
    if (n == -1) {
        return false;
    }
    cin >> monedas;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int diferencia = numeric_limits<int>::max(), num_soluciones = 0;
    vector<bool> sol(n);

    // compute solution
    reparto(v, monedas, sol, diferencia, 0, 0, 0, 0, 0, num_soluciones);
    // write solution
    cout << diferencia << " " << num_soluciones << "\n";

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    while (solve());

    return 0;
}