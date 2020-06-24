#include <iostream>
using namespace std;

struct Count_sort
{
	int* array;
	int max;
	Count_sort(int a) //вводим максимальное значение элементов по модулю
	{
		max = a;
		array = new int[2*max+1];
		for (int i = 0; i < 2 * max + 1; array[i] = 0, i++);
	}
	void add(int a)
	{
		if (abs(a) <= max)
			array[a + max]++;
	}
	void print()
	{
		for (int i = 0; i < 2 * max + 1; i++)
		{
			for (int j = 0; j < array[i]; cout << i-max << ' ', j++);
		}
	}
};

int main()
{
	int n;
	cin >> n;
	Count_sort seq(10000);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		seq.add(a);
	}
	seq.print();
}