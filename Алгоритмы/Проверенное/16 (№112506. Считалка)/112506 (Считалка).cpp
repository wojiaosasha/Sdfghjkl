#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node* next;
	Node(int value)
	{
		val = value;
		next = NULL;
	}
};

struct Circle
{
	Node* last;
	Circle()
	{
		last = NULL;
	}
	void add(int value)
	{
		if (last == NULL)
		{
			last = new Node(value);
			last->next = last;
		}
		else
		{
			Node* tmp = last->next;
			last->next = new Node(value);
			last->next->next = tmp;
			last = last->next;
		}
		
	}
	int del_number(int num)
	{
		int value = -1;
		if (last != NULL)
		{
			if (last->next == last)
			{
				value = last->val;
				delete last;
				last = NULL;
			}
			else
			{
				for (int i = 1; i < num; last = last->next, i++);
				value = last->next->val;
				Node* tmp = last->next;
				last->next = last->next->next;
				delete tmp;
			}
		}
		return value;
	}
};

int main()
{
	int n, k;
	Circle ch;
	cin >> n >> k;
	for (int i = 1; i <= n; ch.add(i), i++);
	int out = ch.del_number(k);
	while (out != -1)
	{
		cout << out << ' ';
		out = ch.del_number(k);
	}
}