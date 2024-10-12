#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//const int MAX = 1000000;

// {Pre: n > 0 && n = length(v) && v[i] >= -50 && v[i] <= 60}
void picos_valles(const vector<int> &v, int n) {
	int picos = 0, valles = 0;
	int i = 1;

	while (i < n - 1) {
		if (v[i - 1] < v[i] && v[i] > v[i + 1]) picos++;
		else if (v[i - 1] > v[i] && v[i] < v[i + 1]) valles++;
		++i;
	}

	cout << picos << " " << valles << "\n";
}
// {Post: # i, j: 0 < i <= j < n-1 : v[i-1] < v[i] && v[i] > v[i+1] || v[j-1] > v[j] && v[j] < v[j+1] }

void solve() {
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for (int j = 0; j < n; ++j) {
		cin >> v[j];
	}
	picos_valles(v, n);
}

int main() {
	int num = 0;

	cin >> num;
	for (int i = 0; i < num; ++i) 	
		solve();	

	return 0;
}