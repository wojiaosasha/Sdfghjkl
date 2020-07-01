#include <iostream>
using namespace std;

void insertion_sort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			int begin = i - 1;
			while (begin >= 0 && a[begin] > a[begin + 1])
			{
				swap(a[begin], a[begin + 1]);
				begin--;
			}
		}
	}
}

int index_max(int* a, int n, int key)
{
	int next=0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[next]) next = i;
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[next] && a[i]>key) next = i;
	}
	return next;
}

void next(int* a, int n)
{
	if (n > 1)
	{
		int begin = n - 2;
		while (begin>= 0 && a[begin] > a[begin + 1]) begin--;
		if (begin>=0) swap(a[begin], a[begin+1+index_max(a + begin + 1, n - begin - 1, a[begin])]);
		insertion_sort(a + begin + 1, n - begin - 1);
	}
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; cin >> a[i], i++);
	next(a, n);
	for (int i = 0; i < n; cout << a[i] << ' ' , i++);
}