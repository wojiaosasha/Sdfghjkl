#include <iostream>
using namespace std;

int dfs(int num, bool* f, int* a, int n)
{
	if (f[num]) return false;
	else
	{
		f[num] = true;
		return dfs(a[num], f, a, n) + 1;
	}
}

int nod(int a, int b)
{
	if (b) return nod(b, a % b);
	else return a;
}

int nok(int a, int b)
{
	return a * b / nod(a, b);
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	bool* f = new bool[n];
	for (int i = 0; i < n; cin >> a[i], a[i]--, f[i]=false, i++);
	int k = 1;
	for (int i = 0; i < n; i++)
		if (!f[i]) k = nok(k, dfs(i, f, a, n));
	cout << k;
	
}