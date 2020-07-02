#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<char> bit;
	bool one=0;
	char a = getchar();
	while (a == '0' || a == '1')
	{
		if (a == '1') one=!one;
		bit.push_back(a);
		a = getchar();
	}
	if (a == 'e') bit.push_back((char)(one+'0'));
	else bit.push_back((char)(!one+'0'));
	for (int i = 0; i < bit.size(); i++)
		cout << bit[i];
}