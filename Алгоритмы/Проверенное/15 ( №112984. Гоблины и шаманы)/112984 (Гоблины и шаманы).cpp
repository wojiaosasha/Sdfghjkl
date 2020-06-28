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

struct Queue
{
	Node* head;
	Node* center;
	Node* tail;
	bool even; //индикатор четности
	Queue()
	{
		head = NULL;
		center = NULL;
		tail = NULL;
		even = true;
	}
	void add(int value)
	{
		if (head == NULL)
		{
			center = new Node(value);
			head=center;
			tail = center;
		}
		else
		{
			tail->next = new Node(value);
			tail = tail->next;
			if (even) center = center->next;
		}
		even = !even;
	}
	void pr_add(int value)
	{
		if (head == NULL || head->next==NULL)
			add(value);
		else
		{
			Node* tmp = center->next;
			center->next = new Node(value);
			center->next->next = tmp;
			if (even) center = center->next;
			even = !even;
		}
	}
	int pop()
	{
		int value = -1;
		if (head != NULL)
		{
			value = head->val;
			if (head->next == NULL)
			{
				delete head;
				head = NULL;
				center = NULL;
				tail = NULL;
			}
			else
			{
				Node* tmp = head;
				head = head->next;
				if (even) center = center->next;
				delete tmp;
			}
			even = !even;
		}
		return value;
	}
	bool empty()
	{
		return !(bool)head;
	}
};

int main()
{
	Queue gob;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char com;
		cin >> com;
		if (com == '+' || com == '*')
		{
			int n;
			cin >> n;
			if (com == '+') gob.add(n);
			else gob.pr_add(n);
		}
		else cout << gob.pop() << endl;
	}
}