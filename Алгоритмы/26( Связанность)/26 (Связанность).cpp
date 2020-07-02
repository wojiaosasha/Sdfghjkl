#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	vector<bool> b(n);
	b[0] = true;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) cin >> a[i][j];

	for (int j = 0; j < 2; j++) 
	{
		for (int k = 0; k < n; k++) 
		{
			for (int i = 0, j = k; i < n; i++) 
				if (b[i] && a[i][j]) b[i] = true;
			for (int i = k, j = 0; j < n; j++) 
				if (b[i] && a[i][j]) b[j] = true;
		}
	}
	bool c = true;
	for (int i = 0; i < n; i++)
		if (!b[i]) 
		{
			c = false;
			break;
		}
	if (c) cout << "YES";
	else cout << "NO";
}