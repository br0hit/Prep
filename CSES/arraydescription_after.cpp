#include <iostream>
#include <vector>
using namespace std;

int goodOrBad(vector<int> &sc, vector<vector<int>> &st)
{
    int n = sc.size();
    vector<vector<int>> g(n, vector<int>(n, -1));
    for (int i = 0, k = 0; i < n; i++)
    {
        for (int j = 0; j < sc[i]; j++, k++)
        {
            g[i][st[k][0] - 1] = st[k][1];
        }
    }

    int mx = 0;
    for (int m = 1; m < (1 << n); m++)
    {
        bool v = true;
        for (int i = 0; i < n && v; i++)
        {
            if (m & (1 << i))
            {
                for (int j = 0; j < n && v; j++)
                {
                    if (g[i][j] != -1 && g[i][j] != ((m & (1 << j)) > 0))
                    {
                        v = false; 
                    }
                }
            }
        }
        if (v)
            mx = max(mx, __builtin_popcount(m));
    }
    return mx;
}

int main()
{
    vector<int> sc1 = {1, 1};
    vector<vector<int>> st1 = {{2, 0}, {1, 0}};
    cout << "Example 1: " << goodOrBad(sc1, st1) << endl;

    vector<int> sc2 = {1, 1, 1};
    vector<vector<int>> st2 = {{2, 1}, {1, 1}, {2, 0}};
    cout << "Example 2: " << goodOrBad(sc2, st2) << endl;

    vector<int> sc3 = {2, 2, 2};
    vector<vector<int>> st3 = {{2, 1}, {3, 0}, {3, 1}, {1, 0}, {1, 1}, {2, 0}};
    cout << "Example 3: " << goodOrBad(sc3, st3) << endl;

    vector<int> sc4 = {2, 3, 4, 1, 2};
    vector<vector<int>> st4 = {{3, 1}, {2, 1}, {1, 0}, {3, 0}, {5, 1}, {5, 0}, {1, 0}, {2, 1}, {4, 1}, {3, 1}, {3, 0}, {1, 0}};
    cout << "Example 4: " << goodOrBad(sc4, st4) << endl;

    return 0;
}