#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> table(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; cin >> table[i][j], j++);
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (table[i][j] > table[i][k] + table[k][j]) table[i][j] = table[i][k] + table[k][j];
	int max = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (max < table[i][j]) max = table[i][j];
	cout << max;
}