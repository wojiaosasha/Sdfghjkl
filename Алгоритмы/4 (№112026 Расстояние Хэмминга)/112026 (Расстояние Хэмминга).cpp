#include <iostream>
#include <string>
using namespace std;

int main()
{
	string first;
	getline(cin, first);
	int n=0;
	for (int i = 0; i < first.size(); i++)
	{
		char a = getchar();
		if (a != first[i]) n++;
	}
	cout << n;
}