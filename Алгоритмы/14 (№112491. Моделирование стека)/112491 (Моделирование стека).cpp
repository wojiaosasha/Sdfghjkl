#include <fstream>
#include <vector>
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

struct Stack
{
	Node* head;
	Stack()
	{
		head = NULL;
	}
	void add(int value)
	{
		if (head == NULL) head = new Node(value);
		else
		{
			Node* tmp = new Node(value);
			tmp->next = head;
			head = tmp;
		}
	}
	int pop()
	{
		int value = -1;
		if (head != NULL)
		{
			value = head->val;
			Node* tmp = head;
			head = head->next;
			delete tmp;
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
	Stack St;
	char com;
	bool error = false;
	ifstream fin("input.txt");
	fin.get(com);
	while (com == '-' || com == '+')
	{
		if (com == '-')
		{
			int res = St.pop();
			if (res == -1)
			{
				error = true;
				break;
			}
		}
		else if (com == '+')
		{
			int value;
			fin >> value;
			St.add(value);
		}
		fin.get(com);
		fin.get(com);
	} 
	fin.close();
	ofstream fout("output.txt");
	if (error) fout << "ERROR";
	else
	{
		if (St.empty()) fout << "EMPTY";
		else
		{
			vector<int> result;
			while (!St.empty()) result.push_back(St.pop());
			for (int i = result.size()-1; i >=0; i--) fout << result[i] << ' ';
		}
	}
	fout.close();
}