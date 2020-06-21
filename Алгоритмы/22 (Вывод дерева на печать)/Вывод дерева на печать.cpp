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
	void add(int value)
	{
		if (root == NULL) root = new Node(value);
		else
		{
			Node* tmp = root;
			while (tmp->val != value)
			{
				if (value > tmp->val)
				{
					if (tmp->right != NULL) tmp = tmp->right;
					else tmp->right = new Node(value);
				}
				else
				{
					if (tmp->left != NULL) tmp = tmp->left;
					else tmp->left = new Node(value);
				}
			}
		}
	}
	int height(Node* tmp)
	{
		if (tmp != NULL)
		{
			return 1 + max(height(tmp->left), height(tmp->right));
		}
		else return 0;
	}
	void print_tree_pr(Node* tmp, int level)
	{
		if (tmp != NULL)
		{
			print_tree_pr(tmp->right, level + 3);
			for (int i = 0; i < level-1; i++)
				cout << ".";
			if (level != 0) cout << "-";
			cout << tmp->val;
			if (tmp->right != NULL && tmp->left != NULL) cout << "<";
			else if (tmp->right != NULL) cout << "/";
			else if (tmp->left != NULL) cout << (char)92; // "\"
			cout << endl;
			print_tree_pr(tmp->left, level + 3);
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
	int n;
	cin >> n;
	while (n != 0)
	{
		oak.add(n);
		cin >> n;
	}
	cout << "Height: " << oak.height(oak.root) << endl;
	oak.print_tree();
}

//void print_tree_pr(Node* tmp, int level)
//{
//	if (tmp != NULL)
//	{
//		print_tree_pr(tmp->right, level + 1);
//		for (int i = 0; i < level; i++)
//			cout << ".";
//		cout << tmp->val << endl;
//		print_tree_pr(tmp->left, level + 1);
//	}
//}