#include <iostream>
using namespace std;
int rev(int* a, int first, int second)
{
	if (a[first] > a[second])
	{
		return first;
	}
	else return second;
}

void heapify (int* a, int n, int parent)
{
	int left = 2 * parent + 1;
	int right = 2 * parent + 2;
	int next = parent;
	if (left < n) next = rev(a, next, left);
	if (right < n) next = rev(a, next, right);
	if (next != parent)
	{
		swap(a[next], a[parent]);
		heapify(a, n, next);
	}
}

void heap_sort(int* a, int n)
{
	if (n > 1)
	{
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(a, n, i);
		for (int i = n - 1; i >= 0; i--)
		{
			swap(a[0], a[i]);
			heapify(a, i, 0);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	if (n > 0)
	{
		int* a = new int[n];
		for (int i = 0; i < n; cin >> a[i], i++);
		heap_sort(a, n);
		for (int i = 0; i < n; cout << a[i] << ' ', i++);
	}
}