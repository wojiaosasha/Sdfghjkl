#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p;

void permut(int* a, int n, int k = 0)
{
	if (k == n)
	{
		p.push_back(0);
		int size = p.size();
		for (int i = 0; i <= n; p[size - 1] = p[size - 1] * 10 + a[i], i++);
	}
	else
	{
		for (int i = k; i <= n; i++)
		{
			swap(a[i], a[k]);
			permut(a, n, k + 1);
			swap(a[i], a[k]);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; a[i] = i + 1, i++);
	permut(a, n - 1);
	sort(p.begin(), p.end());
	for (int i = 0; i < p.size(); cout << p[i] << endl, i++);
}