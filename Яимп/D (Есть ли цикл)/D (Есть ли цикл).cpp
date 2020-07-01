#include <iostream>
#define max 1000000
using namespace std;

int main()
{
	int n;
	cin >> n;
	int** table = new int* [n];
	for (int i = 0; i < n; i++)
	{
		table[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> table[i][j];
			if (table[i][j] == 1) table[i][j] = -10;
			else table[i][j] = max;
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (table[i][j] > table[i][k] + table[k][j]) table[i][j] = table[i][k] + table[k][j];
			}
		}
	}
	bool circle = false;
	for (int i = 0; i < n; i++)
	{
		if (table[i][i] < 0)
		{
			circle = true;
			break;
		}
	}
	cout << circle;
}