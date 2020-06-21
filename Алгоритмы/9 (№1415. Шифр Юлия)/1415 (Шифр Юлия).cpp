#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int k;
	cin >> k;
	for (int i = 0; i < str.size(); i++)
	{
		char a = str[i] - k;
		if (a < 'A') a += 'Z' - 'A'+1;
		cout << a;
	}
}