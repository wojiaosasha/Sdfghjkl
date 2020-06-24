#include <iostream>
#include <vector>
using namespace std;

int digit(int val, int n)
{
	n = pow(10, n - 1);
	return val / n % (n * 10);
}

vector<int> redix_sort(vector<int> a)
{
	if (a.size() > 1)
	{
		int max = a[0];
		for (int i = 1; i < a.size(); i++)
			if (a[i] > max) max = a[i];
		int k = 1;  //макс.кол-во цифр
		while (max >= 10)
		{
			max = max / 10;
			k++;
		};
		for (int j = 1; j <= k; j++)
		{
			for (int i = 1; i < a.size(); i++)
			{
				if (digit(a[i - 1], j) > digit(a[i], j))
				{
					int place = i;
					while (place > 0 && digit(a[i], j) < digit(a[place-1], j)) place--;
					a.insert(a.begin() + place, a[i]);
					a.erase(a.begin() + i + 1);
				}
			}
		}
	}
	return a;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; cin >> a[i], i++);
	a = redix_sort(a);
	for (int i = 0; i < a.size(); cout << a[i] << ' ', i++);
}

//vector<int> redix_sort(vector<int> a)
//{
//	if (a.size() > 1)
//	{
//		int max = a[0];
//		for (int i = 1; i < a.size(); i++)
//			if (a[i] > max) max = a[i];
//		int k = 1;  //макс.кол-во цифр
//		while (max >= 10)
//		{
//			max = max / 10;
//			k++;
//		};
//		for (int j = k - 1; j >= 0; j--)
//		{
//			int val = pow(10, j);
//
//			for (int i = 1; i < a.size(); i++)
//			{
//				if (a[i - 1] / val > a[i] / val)
//				{
//					int place = i - 1;
//					while (place >= 0 && a[i] / val < a[place] / val) place--;
//					a.insert(a.begin() + (place + 1), a[i]);
//					a.erase(a.begin() + i + 1);
//				}
//			}
//		}
//	}
//	return a;
//}