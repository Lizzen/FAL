#include <iostream>

// uncomment to read from a file instead of standard input
//#include <fstream>

using namespace std;

// Pre: true
void fibo(const int n, long long int &a,long long int &b, long long int &c, long long int &d) {
    long long int a_aux = 0, b_aux = 0, c_aux = 0, d_aux = 0;

    if (n == 1) {
        a = 0;
        b = c = d = 1;
    }
    else {
        fibo(n/2, a, b, c, d);
        if (n % 2 == 0) {
            a_aux = (a * a + b * c) % 46337;
            b_aux = (a * b + b * d) % 46337;
            c_aux = (c * a + d * c) % 46337;
            d_aux = (c * b + d * d) % 46337;

            d = d_aux;
            c = c_aux;
            b = b_aux;
            a = a_aux;
        }
        else {
            a_aux = (a * a + b * c) % 46337;
            b_aux = (a * b + b * d) % 46337;
            c_aux = (c * a + d * c) % 46337;
            d_aux = (c * b + d * d) % 46337;

            d = d_aux;
            c = c_aux;
            b = b_aux;
            a = a_aux;

            a_aux = (a * 0 + b * 1) % 46337;
            b_aux = (a * 1 + b * 1) % 46337;
            c_aux = (c * 0 + d * 1) % 46337;
            d_aux = (c * 1 + d * 1) % 46337;

            d = d_aux;
            c = c_aux;
            b = b_aux;
            a = a_aux;
        }
    }
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    // read case
    long long int n, a = 0, b = 0, c = 0, d = 0;
    cin >> n;
    if (n == 0)
        return false;

    // compute solution
    fibo(n, a, b, c, d);

    // write solution
    cout << b << '\n';

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    while (solve());


    return 0;
}