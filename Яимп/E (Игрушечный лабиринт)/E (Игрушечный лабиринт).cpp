#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 2, vector<int>(m + 2)), dist(n + 2, vector<int>(m + 2, 10000));
	for (int i = 0; i <= n + 1; g[i][0] = 1, g[i][m + 1] = 1, i++);
	for (int i = 0; i <= m + 1; g[0][i] = 1, g[n + 1][i] = 1, i++);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; cin >> g[i][j], j++);
	queue<pair<int, int>> q;
	q.push(pair<int, int>{ 1, 1 });
	dist[1][1] = 0;
	vector<pair<int, int>> c = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
	while (!q.empty())
	{
		pair<int, int> v = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = v.first + c[i].first, ny = v.second + c[i].second;
			bool was = 0;
			while (g[nx][ny] != 1)
			{
				was = 0;
				if (dist[nx][ny] > dist[v.first][v.second] + 1)
				{
					dist[nx][ny] = dist[v.first][v.second] + 1;
					was = 1;
				}
				if (g[nx][ny] == 2)
				{
					cout << dist[nx][ny] << endl;
					return 0;
				}
				nx += c[i].first;
				ny += c[i].second;
			}
			nx -= c[i].first;
			ny -= c[i].second;
			if (was) q.push(pair<int, int>{ nx, ny });
		}
	}
}