#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k, s;
	cin >> n >> k >> s;
	vector<int> gas(s+2);
	gas[0] = 0;
	gas[s + 1] = n;
	for (int i = 1; i < s+1; cin >> gas[i], i++);
	s += 2;
	int result = -1; //отнимаем путь от последней заправки до пунка В, так как в нем нет заправки, но все равно нужно проверить его возможность
	int begin = 0;
	while (begin<(s-1))
	{
		if (gas[begin+1] - gas[begin]<=k)
		{
			int next = begin + 1;
			while (next + 1 < s && gas[begin] + k >= gas[next+1]) next++;
			result++;
			begin = next;
		}
		else
		{
			result = -1;
			break;
		}
	}
	cout << result;
}