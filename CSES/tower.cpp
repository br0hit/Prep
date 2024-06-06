#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9+7;

void solve()
{
    int n;
    cin>>n;
    vector<int> k(n,0);
    for(int i=0; i<n; i++) cin>>k[i];

    priority_queue<int> cubestack;
    cubestack.push(-k[0]);

    for (int i = 1; i < n; i++)
    {
        


        int caseval = 0;

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

// multiset<int> cubestack;
// cubestack.insert(k[0]);

// for (int i = 1; i < n; i++)
// {
//     int caseval = 0;
//     for (auto u : cubestack)
//     {
//         if (u > k[i])
//         {
//             cubestack.erase(cubestack.find(u));
//             cubestack.insert(k[i]);
//             caseval = 1;
//             break;
//         }
//     }
//     if (caseval == 0)
//         cubestack.insert(k[i]);
// }

// cout << cubestack.size();