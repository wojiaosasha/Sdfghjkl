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
	Node* head, * tail;
	Queue()
	{
		head = NULL;
		tail = NULL;
	}
	void add(int value)
	{
		if (head == NULL)
		{
			head = new Node(value);
			tail = head;
		}
		else
		{
			tail->next = new Node(value);
			tail = tail->next;
		}
	}
	void alt_seq()
	{
		if (head != NULL && head->next != NULL && head->next->next != NULL)
		{
			Node* a[3];
			a[0] = head;
			a[1] = head->next;
			a[2] = head->next->next;
			while (a[2] != NULL)
			{
				if ((a[0]->val > a[1]->val && a[1]->val > a[2]->val) || (a[0]->val < a[1]->val && a[1]->val < a[2]->val))
				{
					delete a[1];
					a[0]->next = a[2];
					a[1] = a[2];
					a[2] = a[2]->next;
				}
				else
				{
					a[0] = a[1];
					a[1] = a[2];
					a[2] = a[2]->next;
				}
			}
		}
	}
	void print()
	{
		Node* tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->val << ' ';
			tmp = tmp->next;
		}
	}
};

int main()
{
	int n;
	cin >> n;
	Queue a;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		a.add(c);
	}
	a.alt_seq();
	a.print();
}