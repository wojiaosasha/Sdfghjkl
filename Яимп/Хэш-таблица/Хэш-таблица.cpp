// Написать хеш-таблицу методом цепочек
// Построить график времени вполнения алгоритма (ось у) от размера массива (ось х). Для этого нужно сгенерировать массив случайных ключей и значений (порядка миллиона значений),
// вставить их в таблицу, а после по всем имеющимся сгенерированным ключам сделать поиск в таблице. Замерять необходимо именно время поиска. 
// Так необходимо сделать для различных max_len (1, 2, 4, 8 , ..., 256, 512, 1024). Построить таблицу можно в любом удобном для вас инструменте. 
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int max_len = 256; // максимальный размер хеш-таблицы

int random(int end, int begin=0)
{
	return rand() % (end - begin + 1)+begin;
}

char random_char()
{
	return rand() % ('z' - 'A' + 1) + 'A';
}

struct Node 
{
	string value;
	Node* next;
	Node(string str)
	{
		value = str;
		next = NULL;
	}
};

int hesh_code(string key)
{
	// функция должна возвращать сумму кодов букв по модулю max_len
	int sum = 0;
	for (int i = 0; i < key.size(); sum += key[i], i++);
	return sum % max_len;
}

struct Hesh
{
	Node** table;
	Hesh(int n)
	{
		table = new Node * [n];
		for (int i = 0; i < n; table[n] = NULL, i++);
	}
	void set(string value)
	{
		// функция добавляет пару ключ значение в массив
		int num = hesh_code(value);
		Node* tmp = table[num];
		table[num] = new Node(value);
		table[num]->next = tmp;
	}
	Node** search(string key)
	{
		//  функция должна возвращать найденное знаечение по ключу иначе NULL
		Node** tmp = table + hesh_code(key);
		while ((*tmp) != NULL && (*tmp)->value != key) tmp = &(*tmp)->next;
		return tmp;
	}
	void print()
	{
		for (int i = 0; i < max_len; i++)
		{
			Node* tmp = table[i];
			while (tmp != NULL)
				cout << tmp->value << endl;
		}
	}
	bool get(string key)
	{
		// функция должна возвращать найденное знаечение по ключу и удалять его из таблицы иначе NULL
		Node** tmp = search(key);
		if ((*tmp) != NULL)
		{
			Node* to_del = *tmp;
			*tmp = (*tmp)->next;
			delete to_del;
			return true;
		}
		else return false;
	}
};

bool operator<(pair<int, int> left, pair<int, int> right) //сортируем по полю "время" (в обратном порядке)
{
	return (left.second > right.second);
}

bool operator>(pair<int, int> left, pair<int, int> right)
{
	return (left.second < right.second);
}

int main() 
{
	setlocale(LC_ALL, "russian");
	int result[11][10000];
	for (int k = 0; k < 11; k++)
	{
		cout << k << ": start" << endl;
		max_len = pow(2, k);
		Hesh a(max_len);
		string list[10000];
		for (int i = 0; i < 10000; i++)
		{
			int size = random(20); //длина строки (до 20)
			for (int j = 0; j < size; j++)
				list[i]+=random_char();
		}

		/*for (int i = 0; i < 100; i++)
		{
			cout << list[i] << endl;
		}*/

		for (int i = 0; i < 10000; a.set(list[i]), i++);

		bool not_founded = false;
		for (int i = 0; i < 10000; i++)
		{
			unsigned int start = clock();
			not_founded += !*(a.search(list[i]));
			unsigned int finish = clock();
			result[k][i] = finish - start;
		}
		if (not_founded) cout << "not ";
		cout << "all founded" << endl;
		cout << k << ": finish" << endl;
	}
	
	/*for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}*/

	vector<pair<int, int>> res(11);

	for (int i = 0; i < 11; i++)
	{
		int min = result[i][0];
		int max = min;
		for (int j = 1; j < 10000; j++)
		{
			if (result[i][j] < min) min = result[i][j];
			else if (result[i][j] > max) max = result[i][j];
		}
		res[i].first = i;
		res[i].second = (min+max)/2;
	}
	sort(res.begin(), res.end());

	//for (int i = 0; i < 11; cout << res[i].first << ' ' << res[i].second << endl, i++);

	ofstream fout("diagram.txt");

	fout << "время" << endl;
	for (int i = 0; i < 11; i++)
	{
		fout << " ";
		if (res[i].second / 10 > 0) fout << res[i].second;
		else fout << " " << res[i].second;
		fout << "|";
		for (int j = 0; j < res[i].first; fout << "   ", j++);
		fout << " ." << endl;
	}
	fout << "    ";
	for (int i = 0; i < 33; fout << "_", i++);
	fout << "количество (2 в степени n)" << endl;
	fout << "    ";
	for (int i = 1; i <= 11; i++)
	{
		if (i/10>0) fout << i;
		else fout << " " << i;
		fout << " ";
	}
	fout.close();
}