#include<iostream>
#include<vector>
#include<set>
#define max 1000000000
using namespace std;

int main() {
	int n, s, f;
	cin >> n >> s >> f;
	set<pair<int, int>> list;
	vector<pair<int, bool>> flag(n, make_pair(max, true));
	vector<vector<int>> table(n);
	for (int i = 0; i < n; i++)
		table[i].resize(n);
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> table[i][j];
			if (table[i][j] < 0)
				table[i][j] = max;
		}
	}
	s--;
	f--;
	flag[s].first = 0;
	list.insert(make_pair(0, s));
	while (list.size()>0) 
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
	if (flag[f].first < max) cout << flag[f].first;
	else cout << -1;
}