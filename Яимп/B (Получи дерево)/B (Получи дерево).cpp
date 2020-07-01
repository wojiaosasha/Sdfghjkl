#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edge(n - 1);
	vector<int> color(n);
	vector<vector<int>> table(n, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		table[a][b] = 1;
	}
	for (int i = 0; i < n; color[i] = i, i++);
	for (int i = 0; i < n - 1; edge[i] = make_pair(-1, -1), i++);
	for (int k = 0, max, i_col, j_col; k < n - 1; k++)
	{
		max = INT32_MAX;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (table[i][j] != 0 && color[i] != color[j] && table[i][j] < max)
				{
					max = table[i][j];
					edge[k].first = i;
					edge[k].second = j;
					i_col = color[i];
					j_col = color[j];
				}
			}
		}
		if (edge[k].first > edge[k].second) swap(edge[k].first, edge[k].second);
		for (int i = 0; i < n; i++)
			if (color[i] == j_col) color[i] = i_col;
	}
	for (int i = 0; i < n - 1; cout << edge[i].first + 1 << ' ' << edge[i].second + 1 << endl, i++);
}