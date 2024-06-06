#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<int> a(n+m+2,0),b(n+m+2,0);

    for(int i=1; i<= n+m+1; i++ ) cin>>a[i];
    for (int i = 1; i <= n + m + 1; i++)
        cin >> b[i];

    vector<int> comp(n+m+2,0);

    for(int i=1; i<=n+m+1; i++)
    {
        if(a[i]>b[i]) comp[i]=1;
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