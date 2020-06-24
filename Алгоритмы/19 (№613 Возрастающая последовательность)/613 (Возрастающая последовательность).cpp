#include <iostream>
#include <vector>
using namespace std;

vector<int> max_rise(vector<int> a)
{
	if (a.size() > 1)
	{
		vector<vector<int>> var(1);
		int num = 1;
		var[0].push_back(a[0]);
		while (num < a.size())
		{
			int s = var.size();
			for (int i = 0; i < s; i++)
			{
				if (a[num] > var[i][var[i].size() - 1])
					var[i].push_back(a[num]);
				else if (a[num] < var[i][var[i].size() - 1])
				{
					var.insert(var.end(), var[i]);
					int size = var[i].size()-1;
					while (size>=0)
					{
						if (var[i][size] >= a[num])
							var[i].erase(var[i].begin() + size);
						size--;
					}
					var[i].push_back(a[num]);
				}
			}
			num++;
		}
		int max = 0;
		num = 0;
		for (int i = 0; i < var.size(); i++)
		{
			if (var[i].size() > max)
			{
				max = var[i].size();
				num = i;
			}
		}
		if (max>0) a = var[num];
	}
	return a;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; cin >> a[i], i++);
	a = max_rise(a);
	cout << a.size() << endl;
	for (int i = 0; i < a.size(); cout << a[i] << ' ', i++);
}
