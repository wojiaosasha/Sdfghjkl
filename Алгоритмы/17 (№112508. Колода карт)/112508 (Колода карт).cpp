#include <fstream>
using namespace std;

struct Node
{
	string card;
	Node* prev;
	Node* next;
	Node(string str)
	{
		card = str;
		prev = NULL;
		next = NULL;
	}
};

struct Deque
{
	Node* head;
	Node* tail;
	Deque()
	{
		head = NULL;
		tail = NULL;
	}
	bool empty()
	{
		return !(bool)head;
	}
	void make_empty() //для удаления из дека с одним элементом
	{
		delete head;
		head = NULL;
		tail = NULL;
	}
	void push_in_empty(string str)
	{
		head = new Node(str);
		tail = head;
	}
	void push_back(string str)
	{
		if (empty()) push_in_empty(str);
		else
		{
			tail->next = new Node(str);
			tail->next->prev = tail;
			tail = tail->next;
		}
	}
	void push_front(string str)
	{
		if (empty()) push_in_empty(str);
		else
		{
			head->prev = new Node(str);
			head->prev->next = head;
			head = head->prev;
		}
	}
	string pop_front()
	{
		string result = "";
		if (!empty())
		{
			result = head->card;
			if (head->next == NULL) make_empty();
			else
			{
				head = head->next;
				delete head->prev;
				head->prev = NULL;
			}
		}
		return result;
	}
	string pop_back()
	{
		string result = "";
		if (!empty())
		{
			result = tail->card;
			if (tail->prev == NULL) make_empty();
			else
			{
				tail = tail->prev;
				delete tail->next;
				tail->next = NULL;
			}
		}
		return result;
	}
	bool exist(string str)
	{
		bool exist = false;
		if (!empty())
		{
			for (Node* i = head; i != NULL; i = i->next)
			{
				if (i->card == str)
				{
					exist = true;
					break;
				}
			}
		}
		return exist;
	}
};

int main()
{
	bool correct = true;
	Deque Deck;
	ifstream fin("input.txt");
	while (!fin.eof())
	{
		char com;
		fin.get(com);
		if (com == '+' || com == '#')
		{
			string card;
			fin >> card;
			if (!Deck.exist(card))
			{
				if (com == '+') Deck.push_front(card);
				else if (com == '#') Deck.push_back(card);
			}
			else
			{
				correct = false;
				break;
			}
		}
		else if (com == '^' || com == '/')
		{
			if (!Deck.empty())
			{
				if (com == '^') Deck.pop_front();
				else if (com == '/') Deck.pop_back();
			}
			else
			{
				correct = false;
				break;
			}
		}
	}
	fin.close();
	ofstream fout("output.txt");

	if (correct)
	{
		if (!Deck.empty())
		{
			while (!Deck.empty()) fout << Deck.pop_front() << ' ';
		}
		else fout << "EMPTY";
	}
	else fout << "ERROR";
	fout.close();
}