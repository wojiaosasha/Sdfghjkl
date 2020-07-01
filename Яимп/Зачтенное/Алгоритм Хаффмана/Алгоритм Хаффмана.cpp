#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

struct freque
{
	char sym;
	int time;
	freque(char a)
	{
		sym = a;
		time = 1;
	}
};

struct replac
{
	char sym;
	vector<bool> code;
};

bool operator>(freque left, freque right)
{
	return left.time > right.time;
}
bool operator<(freque left, freque right)
{
	return left.time < right.time;
}
bool operator>(replac left, replac right)
{
	return left.sym > right.sym;
}
bool operator<(replac left, replac right)
{
	return left.sym < right.sym;
}

vector<replac> dict;

void tree(vector<freque>* a, vector<bool>* rep)
{
	if ((*a).size() > 1)
	{
		int i = (*a).size()-1;
		int sum_left = 0;
		for (int j = 0; j < i; sum_left+=(*a)[j].time, j++);
		int sum_right = (*a)[i].time;
		while (i > 1 && sum_left > sum_right)
		{
			i--;
			sum_left -= (*a)[i].time;
			sum_right += (*a)[i].time;
		}
		vector<freque> left((*a).begin(), (*a).begin() + i);
		vector<freque> right((*a).begin()+i, (*a).end());
		(*rep).push_back(false);
		tree(&left, rep);
		(*rep)[(*rep).size() - 1] = true;
		tree(&right, rep);
		(*rep).pop_back();
	}
	else if ((*a).size() == 1)
	{
		replac p;
		p.sym = (*a)[0].sym;
		p.code.insert(p.code.begin(), (*rep).begin(), (*rep).end());
		dict.push_back(p);
	}
}

void encode(vector<freque>* a)
{
	sort((*a).begin(), (*a).end());
	vector<bool> b;
	tree(a, &b);
	sort(dict.begin(), dict.end());
}

bool operator==(vector<bool> left, vector<bool> right)
{
	if (left.size() == right.size())
	{
		bool equal = true;
		for (int i = 0; i < left.size(); i++)
		{
			if (left[i] != right[i])
			{
				equal = false;
				break;
			}
		}
		return equal;
	}
	else return false;
}

int find(vector<bool>* a)
{
	int num = -1;
	for (int i = 0; i < dict.size(); i++)
	{
		if ((*a) == dict[i].code)
		{
			num = i;
			break;
		}
	}
	return num;
}

int main()
{
	setlocale(LC_ALL, "russian");
	ifstream fin;
	fin.open("text.txt");
	ofstream fout;
	fout.open("encode.txt");

	vector<freque> s;

	int k = 0;
	while (!fin.eof())
	{
		k++;
		char a = fin.get();
		bool exist = false;
		for (int j = 0; j < s.size(); j++)
		{
			if (a == s[j].sym)
			{
				exist = true;
				s[j].time++;
				break;
			}
		}
		if (!exist)
		{
			freque c(a);
			s.push_back(c);
		}
	}
	k--;

	encode(&s);

	//for (int i = 0; i < s.size(); i++) //вывод таблицы частотности
	//	cout << s[i].sym << ' ' << s[i].time << endl;

	fin.close();
	fin.open("text.txt");

	while (!fin.eof())
	{
		char a = fin.get();
		int j = 0;
		while (j<dict.size() && dict[j].sym != a) j++;
		if (j < dict.size())
		{
			for (int k = 0; k < dict[j].code.size(); k++)
			{
				fout << dict[j].code[k];
			}
		}
		else fout << endl << "error; symbol has not founded" << endl; //ни разу не выводилось, но пусть будет.........
	}

	fin.close();
	fout.close();
	fout.open("dictionary.txt");

	for (int i = 0; i < dict.size(); i++)
	{
		fout << dict[i].sym << ' ';
		for (int k = 0; k < dict[i].code.size(); k++)
		{
			fout << dict[i].code[k];
		}
		fout << endl;
	}

	fout.close();
	fin.open("encode.txt");
	fout.open("decode.txt");

	vector<bool> word;

	while (k>0 && !fin.eof())
	{
		char let = fin.get();
		if (let == '0') word.push_back(false);
		else if (let == '1') word.push_back(true);
		else continue;
		int decode = find(&word);
		if (decode >= 0)
		{
			fout << dict[decode].sym;
			word.clear();
			k--;
		}
	}
	fout.close();
}