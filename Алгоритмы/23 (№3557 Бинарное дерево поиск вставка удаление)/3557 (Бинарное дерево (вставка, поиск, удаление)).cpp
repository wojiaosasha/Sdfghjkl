#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int val;
	Node* left, * right;
	Node(int value)
	{
		val = value;
		left = NULL;
		right = NULL;
	}
};

struct bin_tree
{
	Node* root;
	bin_tree()
	{
		root = NULL;
	}
	bool add(int value)
	{
		Node** tmp = search_pr(value);
		bool done = false;
		if ((*tmp) == NULL) done = ((*tmp) = new Node(value));
		return done;
	}
	Node** search_max(Node** tmp)
	{
		if ((*tmp) != NULL)
			while ((*tmp)->left != NULL) tmp = &((*tmp)->left);
		return tmp;
	}
	Node** search_pr(int value)
	{
		Node** tmp = &root;
		while (*tmp != NULL && (*tmp)->val != value)
		{
			if (value > (*tmp)->val) tmp = &((*tmp)->left);
			else if (value < (*tmp)->val) tmp = &((*tmp)->right);
		}
		return tmp;
	}
	bool search(int value)
	{
		return (bool)(*search_pr(value));
	}
	bool delet(int value)
	{
		bool done = true;
		Node** tmp = search_pr(value);
		if (*tmp) delet_pr(tmp);
		else done = false;
		return done;
	}
	void delet_pr(Node** del)
	{
		if (*del)
		{
			if ((*del)->right != NULL && (*del)->left != NULL) //у уд.элем. есть оба потомка
			{
				Node** tmp = search_max(&((*del)->right));
				(*del)->val = (*tmp)->val;
				delet_pr(tmp); //рекурсивно удаляем макс.(крайний левый) элем. правого поддерева
			}
			else if ((*del)->right != NULL) //есть правый потомок (но нет левого)
			{
				Node* tmp = (*del)->right;
				(*del)->val = (*del)->right->val;
				(*del)->right = (*del)->right->right;
				delete tmp; //правое поддерево переносится на место удаляемого элемента
			}
			else if ((*del)->left != NULL) //есть левый потомок (но нет правого)
			{
				Node* tmp = (*del)->left;
				(*del)->val = (*del)->left->val;
				(*del)->left = (*del)->left->left;
				delete tmp; //левое поддерево переносится на место удаляемого элемента
			}
			else //нет потомков
			{
				delete* del;
				*del = NULL;
			}
		}
	}
	void print_tree_pr(Node* tmp, int level)
	{
		if (tmp != NULL)
		{
			print_tree_pr(tmp->right, level + 1);
			for (int i = 0; i < level; i++)
				cout << ".";
			cout << tmp->val << endl;
			print_tree_pr(tmp->left, level + 1);
		}
	}
	void print_tree()
	{
		print_tree_pr(root, 0);
	}
};

int main()
{
	bin_tree oak;
	for (int i=0; i<1000; i++)
	{
		string com;
		cin >> com;
		if (com == "PRINTTREE") oak.print_tree();
		else
		{
			int n;
			cin >> n;
			if (com == "ADD")
			{
				if (oak.add(n)) cout << "DONE";
				else cout << "ALREADY";
			}
			else if (com == "DELETE")
			{
				if (oak.delet(n)) cout << "DONE";
				else cout << "CANNOT";
			}
			else if (com == "SEARCH")
			{
				if (oak.search(n)) cout << "YES";
				else cout << "NO";
			}
			cout << endl;
		}
	}
}