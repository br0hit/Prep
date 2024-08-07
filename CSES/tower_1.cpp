#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,a,n) for(i=a; i<n; i++);
int modval = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> k(n, 0);
    for (int i = 0; i < n; i++)
        cin >> k[i];

    multiset<int> cubestack;
    cubestack.insert(k[0]);

    for (int i = 1; i < n; i++)
    {
        int caseval = 0;
        // if (maxval == k[i])
        // {
        //     cubestack.insert(k[i]);
        //     continue;
        // }

        auto val = cubestack.upper_bound(k[i]);

        if(val!=cubestack.end())
        {
            int temp = *val;
            cubestack.erase(val);
            cubestack.insert(k[i]);
            caseval=1;
        }

        // for (auto u : cubestack)
        // {
        //     if (u > k[i])
        //     {
        //         cubestack.erase(cubestack.find(u));
        //         cubestack.insert(k[i]);
        //         caseval = 1;
        //         break;
        //     }
        // }

        if (caseval == 0)
            cubestack.insert(k[i]);
    }

    cout << cubestack.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin >> t; while (t--)
    solve();
    return 0;
}