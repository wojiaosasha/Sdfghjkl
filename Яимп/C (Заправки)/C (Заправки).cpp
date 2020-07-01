#include<iostream>
#include<vector>
#include<set>
#define max 1000000000
using namespace std;

int dij(int** table, int n) //от первой до последней (n) вершины
{
	set<pair<int, int>> list;
	vector<pair<int, bool>> flag(n, make_pair(max, true));
	
	flag[0].first = 0;
	list.insert(make_pair(0, 0));
	while (list.size() > 0)
	{
		int k = list.begin()->second;
		flag[k].second = false;
		list.erase(list.begin());
		for (int i = 0; i < n; ++i)
			if (flag[i].second && flag[i].first > flag[k].first + table[k][i])
			{
				list.erase(make_pair(flag[i].first, i));
				flag[i].first = flag[k].first + table[k][i];
				list.insert(make_pair(flag[i].first, i));
			}
	}
	if (flag[n-1].first < max) return flag[n-1].first;
	else return -1;
}

int main() 
{
	int n, m;
	cin >> n;
	int* price = new int[n];
	for (int i = 0; i < n; cin >> price[i], i++);
	cin >> m;
	int** table = new int* [n];
	for (int i = 0; i < n; i++)
	{
		table[i] = new int [n];
		for (int j = 0; j < n; table[i][j]=max, j++);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		table[a][b] = price[a];
		table[b][a] = price[b];
	}
	cout << dij(table, n);
}