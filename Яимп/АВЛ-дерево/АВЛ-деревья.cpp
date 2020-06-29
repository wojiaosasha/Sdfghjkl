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

struct bin_tree //далее в некоторых местах написано "указатель" вместо "указатель на указатель" - это неточность в целях уменьшения текста:)
{
	Node* root;
	bin_tree()
	{
		root = NULL;
	}
	bool add(int value) //добавление ключа
	{
		Node** tmp = search_pr(value); //см. комментарий к этой функции ниже
		bool done = false;
		if ((*tmp) == NULL)
		{
			done = ((*tmp) = new Node(value));
			balance(&root); //балансировка
		}
		return done;
	}
	Node** search_max(Node** tmp) //находит указатель (на указатель) на камсимальный элемент в поддереве
	{
		if ((*tmp) != NULL)
			while ((*tmp)->left != NULL) tmp = &((*tmp)->left);
		return tmp;
	}
	int max_key() //находит ключ максимального элемента
	{
		if (root == NULL) return -1;
		else
		{
			Node* tmp = root;
			while (tmp->left != NULL) tmp = tmp->left;
			return tmp->val;
		}
	}
	int min_key() //находит ключ минимального элемента
	{
		if (root == NULL) return -1;
		else
		{
			Node* tmp = root;
			while (tmp->right != NULL) tmp = tmp->right;
			return tmp->val;
		}
	}
	Node** search_pr(int value) //поиск указателя на элемент с введенным ключом (если элемента нет, выводит указатель на место, где он должен быть (это используется в добавлении))
	{
		Node** tmp = &root;
		while (*tmp != NULL && (*tmp)->val != value)
		{
			if (value > (*tmp)->val) tmp = &((*tmp)->left);
			else if (value < (*tmp)->val) tmp = &((*tmp)->right);
		}
		return tmp;
	}
	bool search(int value) //существует ли элемент
	{
		return (bool)(*search_pr(value));
	}
	bool delet(int value) //удаление по ключу (находит элемент и запускает удаление по указателю)
	{
		bool done = true;
		Node** tmp = search_pr(value);
		if (*tmp)
		{
			delet_pr(tmp);
			balance(&root); //балансировка
		}
		else done = false;
		return done;
	}
	void delet_pr(Node** del) //удаление по указателю
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
				Node* tmp = (*del);
				(*del) = (*del)->right;
				delete tmp; //правое поддерево переносится на место удаляемого элемента

			}
			else if ((*del)->left != NULL) //есть левый потомок (но нет правого)
			{
				Node* tmp = (*del);
				(*del) = (*del)->left;
				delete tmp; //левое поддерево переносится на место удаляемого элемента
			}
			else //нет потомков
			{
				delete* del;
				*del = NULL;
			}
		}
	}
	void print_tree_pr(Node* tmp, int level) //вывод в виде дерева
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
	void print_lpr_pr(Node* tmp) //вывод левый-родитель-правый
	{
		if (tmp != NULL)
		{
			print_lpr_pr(tmp->left);
			cout << tmp->val << ' ';
			print_lpr_pr(tmp->right);
		}
	}
	void print_lpr() 
	{
		print_lpr_pr(root);
	}
	void print_plr_pr(Node* tmp) //вывод родитель-левый-правый
	{
		if (tmp != NULL)
		{
			cout << tmp->val << ' ';
			print_plr_pr(tmp->left);
			print_plr_pr(tmp->right);
		}
	}
	void print_plr()
	{
		print_plr_pr(root);
	}
	void print_lrp_pr(Node* tmp) //вывод левый-правый-родитель
	{
		if (tmp != NULL)
		{
			print_lrp_pr(tmp->left);
			print_lrp_pr(tmp->right);
			cout << tmp->val << ' ';
		}
	}
	void print_lrp()
	{
		print_lrp_pr(root);
	}
	int height(Node* tmp) //вывод высоты по указателю на корень дерева (поддерева)
	{
		if (tmp != NULL)
		{
			return 1 + max(height(tmp->left), height(tmp->right));
		}
		else return 0;
	}
	void balance(Node** tmp)
	{
		if (*tmp != NULL)
		{
			balance(&(*tmp)->right);
			balance(&(*tmp)->left);
			if (abs(height((*tmp)->right) - height((*tmp)->left)) > 1) //поддерево не сбалансировано
			{
				if (height((*tmp)->right) > height((*tmp)->left)) //высота правого поддерева больше (значит, правый потомок точно существует)
				{
					if (height((*tmp)->right->left) > height((*tmp)->right->right)) big_left_bal(tmp);
					else small_left_bal(tmp);
				}
				else //высота левого поддерева больше (левый потомок точно существует)
				{
					if (height((*tmp)->left->right) > height((*tmp)->left->left)) big_right_bal(tmp);
					else small_right_bal(tmp);
				}
			}
		}
	}
	void small_left_bal(Node** tmp) //малое левое вращение
	{
		Node* a, * b;
		a = *tmp;
		b = a->right;
		a->right = b->left;
		b->left = a;
		*tmp = b;
	}
	void small_right_bal(Node** tmp) //малое правое вращение
	{
		Node* a, * b;
		a = *tmp;
		b = a->left;
		a->left = b->right;
		b->right = a;
		*tmp = b;
	}
	void big_left_bal(Node** tmp) //большое левое вращение
	{
		Node* a, * b, * c;
		a = *tmp;
		b = a->right;
		c = b->left;
		a->right = c->left;
		b->left = c->right;
		c->left = a;
		c->right = b;
		*tmp = c;
	}
	void big_right_bal(Node** tmp) //большое правое вращение
	{
		Node* a, * b, * c;
		a = *tmp;
		b = a->left;
		c = b->right;
		a->left = c->right;
		b->right = c->left;
		c->right = a;
		c->left = b;
		*tmp = c;
	}
};

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "Доступные команды:" << endl;
	cout << "add n" << " - добавление ключа n (только натуральные числа)" << endl;
	cout << "search n" << " - поиск ключа n" << endl;
	cout << "delete n" << " - удаление ключа n" << endl;
	cout << "print lpr/plr/lrp/tree " << " - вывести указанным способом (левый-корень-правый/корень-левый-правый/левый-правый-корень/в виде дерева)" << endl;
	cout << "min" << " - вывод минимального элемента" << endl;
	cout << "max" << " - вывод максимального элемента" << endl;
	cout << "end" << " - завершить программу" << endl;
	cout << endl;
	bin_tree oak;
	string com;
	cin >> com;
	while (com != "end")
	{
		if (com == "print")
		{
			cin >> com;
			if (oak.min_key() != -1) //индикатор того что дерево пустое
			{
				if (com == "tree") oak.print_tree();
				else if (com == "lpr") oak.print_lpr();
				else if (com == "plr") oak.print_plr();
				else if (com == "lrp") oak.print_lrp();
			}
			else if (com == "tree" || com == "lpr" || com == "plr" || com == "lrp") 
				cout << "tree is empty";
			else
			{
				cout << "wrong command";
				char a = getchar();
				while (a != 10) a = getchar();
			}
		}
		else if (com == "min")
		{
			int min = oak.min_key();
			if (min > 0) cout << min;
			else cout << "tree is empty";
		}
		else if (com == "max")
		{
			int max = oak.max_key();
			if (max > 0) cout << max;
			else cout << "tree is empty";
		}
		else if (com == "add" || com == "delete" || com == "search")
		{
			int n=0;
			char a = getchar();
			if (a != 10) a = getchar();
			while (a==' ') a = getchar();
			if (a == '-' || a == '0' || a==10)
			{
				while (a != 10) a = getchar();
				cout << "error (введите натуральное число)";
			}
			else
			{
				while (a >= '0' && a <= '9')
				{
					n = n * 10 + (a - '0');
					a = getchar();
				}
				if (n > 0 && a==10)
				{
					while (a != 10) a = getchar();
					if (com == "add")
					{
						if (oak.add(n)) cout << "done";
						else cout << "already added";
					}
					else if (com == "delete")
					{
						if (oak.delet(n)) cout << "done";
						else cout << "doesn't exist";
					}
					else if (com == "search")
					{
						if (oak.search(n)) cout << "exist";
						else cout << "doesn't exist";
					}
				}
				else if (n > 0)
				{
					while (a != 10) a = getchar();
					cout << "error (введите, пожалуйста, число ТОЛЬКО цифрами)";
				}
				else
				{
					while (a != 10) a = getchar();
					cout << "error (введите, пожалуйста, число ЦИФРАМИ)";
				}
			}
		}
		else
		{
			char a=getchar();
			while (a != 10) a = getchar();
			cout << "wrong command";
		}
		cout << endl << endl;
		cin >> com;
	}
}