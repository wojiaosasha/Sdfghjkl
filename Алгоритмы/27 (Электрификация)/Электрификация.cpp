#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#define paired vector<pair<int, int>>
using namespace std;

void sort(paired &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            if (ans[i].first < ans[j].first || (ans[i].first == ans[j].first && ans[i].second < ans[j].second))
            {
                swap(ans[i], ans[j]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    paired edges(n - 1);

    int **map = new int *[n];
    int *color = new int[n];

    for (int i = 0; i < n; i++)
    {
        color[i] = i;
        map[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        edges[i] = make_pair(-1, -1);
    }

    for (int k = 0, mn, iCol, jCol; k < n - 1; k++)
    {
        mn = INT32_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (map[i][j] != 0 && color[i] != color[j] && map[i][j] < mn)
                {
                    mn = map[i][j];

                    edges[k].first = i;
                    edges[k].second = j;

                    iCol = color[i];
                    jCol = color[j];
                }
            }
        }

        if (edges[k].first > edges[k].second)
        {
            swap(edges[k].first, edges[k].second);
        }

        for (int i = 0; i < n; i++)
        {
            if (color[i] == jCol)
            {
                color[i] = iCol;
            }
        }
    }

    sort(edges);

    for (int i = 0; i < n - 1; i++)
    {
        cout << edges[i].first + 1 << ' ' << edges[i].second + 1 << '\n';
    }
}