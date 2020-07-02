#include <iostream>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int r, n;

    cin >> r >> n;

    vector<string> pattern(r);
    vector<string> replacement(r);

    getline(cin, pattern[0]);

    for (int i = 0; i < r; i++)
    {
        getline(cin, pattern[i]);
        getline(cin, replacement[i]);
    }

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);

        vector<string> ans(line.size() + 1);
        ans[0] = "";

        for (int j = 1; j <= line.size(); j++)
        {
            ans[j] = ans[j - 1] + line[j - 1];

            for (int k = 0; k < r; k++)
            {
                int l = pattern[k].size();

                if (l <= j && line.compare(j - l, l, pattern[k]) == 0 && ans[j - l].size() + 1 < ans[j].size())
                    ans[j] = ans[j - l] + replacement[k];
            }
        }

        cout << ans[line.size()] << '\n';
    }

    return 0;
}
