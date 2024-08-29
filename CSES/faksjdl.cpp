#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 15;

int goodOrBad(vector<int> &sc, vector<vector<int>> &st)
{
    int n = sc.size();
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < st.size(); i++)
    {
        int u = st[i][0] - 1;
        int v = st[i][1];
        g[u].push_back({i, v});
    }

    int mx = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        bool valid = true;
        for (int i = 0; i < n && valid; i++)
        {
            if (mask & (1 << i))
            {
                for (auto &p : g[i])
                {
                    int j = p.first;
                    int v = p.second;
                    if (v != ((mask >> (st[j][0] - 1)) & 1))
                    {
                        valid = false;
                        break;
                    }
                }
            }
        }
        if (valid)
            mx = max(mx, __builtin_popcount(mask));
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