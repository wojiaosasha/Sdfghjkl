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
	cout << oak.height(oak.root);
}