#include <iostream>
#include <vector>
using namespace std;

vector<int> insertion_sort(vector<int> a)
{
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i-1] > a[i])
		{
			int place = 0;
			while (place < i-1 && a[i] > a[place]) place++;
			a.insert(a.begin()+place, a[i]);
			a.erase(a.begin() + i + 1);
		}
	}
	return a;
}

vector<int> bucket_sort(vector<int> a)
{
	if (a.size() > 1)
	{
		const int range = 10; //задаем диапазон разбиения
		int min = a[0], max = a[0];
		for (int i = 1; i < a.size(); i++)
		{
			if (a[i] < min) min = a[i];
			else if (a[i] > max) max = a[i];
		}
		if (min - max + 1 > range)
		{
			int amt = (max - min + 1) / range + (bool)((max - min + 1) % range);
			vector<vector<int>> bucket(amt);
			for (int i = 0; i < a.size(); i++)
				bucket[a[i] / range].push_back(a[i]);
			a.clear();
			for (int i = 0; i < amt; i++)
			{
				bucket[i] = bucket_sort(bucket[i]);
				a.insert(a.end(), bucket[i].begin(), bucket[i].end());
			}
		}
		else
			a = insertion_sort(a);
	}
	return a;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; cin >> a[i], i++);
	a = bucket_sort(a);
	for (int i = 0; i < a.size(); cout << a[i] << ' ', i++);
}