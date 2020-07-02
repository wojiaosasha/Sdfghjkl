#include <fstream>
#include <iostream>

using namespace std;

ofstream fout("output.txt");

struct Node
{
    int count;
    string word;

    Node *next;
    Node *previous;
};

class List
{
    Node *Head, *Tail;

public:
    int size = 0;

    List() : Head(NULL), Tail(NULL) {}
    ~List();

    void Append(string word);
    void Sort();
    void Print();
};

List::~List()
{
    while (Head != NULL)
    {
        Tail = Head->next;
        delete Head;
        Head = Tail;
    }
};

void List::Sort()
{
    Node *temp = Head;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {

            if (temp->count < temp->next->count)
            {
                swap(temp->count, temp->next->count);
                swap(temp->word, temp->next->word);
            }

            temp = temp->next;
        }
        temp = Head;
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (temp->count == temp->next->count)
            {
                if (temp->word > temp->next->word)
                {
                    swap(temp->count, temp->next->count);
                    swap(temp->word, temp->next->word);
                }
            }
            temp = temp->next;
        }
        temp = Head;
    }
};

void List::Append(string word)
{
    Node *temp = Head;

    // слово есть в списке -> увеличиваем количество
    while (temp != NULL)
    {
        if (temp->word == word)
        {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    // Если слова нет в списке -> добавляем в конец
    Node *node = new Node;
    node->next = node->previous = NULL;
    node->word = word;
    node->count = 1;

    if (Head != NULL)
    {
        node->previous = Tail;
        Tail->next = node;
        Tail = node;
    }
    else
    {
        node->previous == NULL;
        Head = Tail = node;
    }
    size++;
};

void List::Print()
{
    Sort();
    Node *temp = Head;
    while (temp != NULL)
    {
        fout << temp->word << " " << temp->count << endl;
        temp = temp->next;
    }
};

int main()
{
    ifstream file("input.txt");
    string x;

    List list;

    while (file >> x)
    {
        list.Append(x);
    }

    list.Print();

    return 0;
}