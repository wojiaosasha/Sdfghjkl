#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct lesson
{
	int start;
	int finish;
};

bool operator>(lesson left, lesson right)
{
	if (left.finish == right.finish) return (left.finish - left.start > right.finish - right.start);
	else return (left.finish > right.finish);
}

bool operator<(lesson left, lesson right)
{
	if (left.finish == right.finish) return (left.finish - left.start < right.finish - right.start);
	else return (left.finish < right.finish);
}

int zhadina(vector<lesson>* t)
{
	int begin = 0, end = (*t).size()-1;
	while (begin < end)
	{
		int next = begin + 1;
		while (next <= end && ((*t)[begin].finish == (*t)[next].finish || (*t)[begin].finish > (*t)[next].start))
		{
			(*t).erase((*t).begin() + next);
			end--;
		}
		begin++;
	}
	return (*t).size();
}

int main()
{
	int n;
	cin >> n;
	vector<lesson> table(n);
	for (int i = 0; i < n; cin >> table[i].start >> table[i].finish, i++);
	sort(table.begin(), table.end());
	cout << zhadina(&table);
}