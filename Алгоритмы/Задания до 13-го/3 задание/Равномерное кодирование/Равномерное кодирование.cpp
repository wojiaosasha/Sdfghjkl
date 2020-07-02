#include <vector>
#include <fstream>
using namespace std;


struct list
{
	char sym;
	string code;
	list(char a)
	{
		sym = a;
		code = "";
	}
};

list make_list(char a)
{
	list some(a);
	return some;
}

vector<list> dict;

void make_code(string* str, int num, int i)
{
	if (num == 0) (*str) += i + '0';
	else
	{
		make_code(str, num - 1, i / 2);
		(*str) += i % 2 + '0';
	}
}

void encode(int n)
{
	for (int i = 0; i < dict.size(); i++)
		make_code(&dict[i].code, n, i);
}

int main()
{
	setlocale(LC_ALL, "russian");
	int k=0;
	ifstream fin;
	fin.open("text.txt");

	while (!fin.eof())
	{
		char a = fin.get();
		
		bool exist = false;
		for (int i = 0; i < dict.size(); i++)
		{
			if (dict[i].sym == a)
			{
				exist = true;
				break;
			}
		}
		if (!exist) dict.push_back(make_list(a));
		k++;
	}
	k--;

	int num;
	for (num = 0; pow(2, num) < dict.size(); num++);
	encode(num-1);

	fin.close();
	fin.open("text.txt");
	ofstream fout;
	fout.open("encode.txt");

	for (int i = 0; i < k; i++)
	{
		char a = fin.get();
		for (int j = 0; j < dict.size(); j++)
		{
			if (dict[j].sym == a)
			{
				fout << dict[j].code;
				break;
			}
		}
	}

	fin.close();
	fout.close();
	fout.open("dictionary.txt");
	for (int i = 0; i < dict.size(); fout << dict[i].sym << ' ' << dict[i].code << endl, i++);
	fout.close();

	fin.open("encode.txt");
	fout.open("decode.txt");

	string c = "";
	while (!fin.eof())
	{
		char a = fin.get();
		if (a == '0' || a == '1') c += a;
		else continue;
		if (c.size() == num)
		{
			for (int j = 0; j < dict.size(); j++)
			{
				if (dict[j].code == c)
				{
					fout << dict[j].sym;
					break;
				}
			}
			c = "";
		}
	}

	fin.close();
	fout.close();
	
}