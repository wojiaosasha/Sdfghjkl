#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

void sep(int k, int m, int n) {
	if (n == 0) 
	{
		for (int i = 0; i < k; cout << a[i] << ' ', i++);
		cout << endl;
	}
	else 
	{
		for (int i = n; i >= m; i--) 
		{
			a[k] = i;
			sep(k + 1, i, n - i);
		}
	}
}

int main() {
	int n;
	cin >> n;
	a.resize(n+10);
	sep(0, 1, n);
}