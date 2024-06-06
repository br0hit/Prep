#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> a,b;
    int temp;

    a.resize(n);
    b.resize(n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>temp;
            a[i].push_back(temp);
        } 
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            b[i].push_back(temp);
        }
    }

    


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}