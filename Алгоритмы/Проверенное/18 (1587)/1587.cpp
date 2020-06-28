#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> seq;
	int size;
	cin >> size;
	if (size < 2)
	{
		cout << 0;
	}
	else
	{
		int k = 0;
		int n;
		for (int i = 0; i < size; i++)
		{
			cin >> n;
			seq.push_back(n);

			if (seq.size() > 2)
			{
				int temp = seq.size();
				int prev = temp - 3;
				int middle = temp - 2;
				int next = temp - 1;

				if (!((seq[prev] < seq[middle]) && (seq[middle] > seq[next]) || (seq[prev] > seq[middle]) && (seq[middle] < seq[next])))
				{
					seq.erase(seq.begin() + middle);
					k++;
				}
			}
		}
		if ((seq.size() == 2) && (seq[0] == seq[1]))
			k++;

		cout << k << endl;
	}
}