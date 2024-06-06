#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll m,x;
    cin>>m>>x;

    vector<ll> c(m,0),h(m,0);

    for(ll i=0; i<m; i++) 
    {
        cin>>c[i]>>h[i];
    }

    vector<vector<ll>> dp(m,vector<ll>(1e10,1e10));

    // for(ll i=0; i<m; i++)
    // {
    //     if(c[i-1]<=m)
    //     {
    //         dp[i][m] = max(h[i - 1] + dp[i][m * x - x], dp[i - 1][m - 1]);
    //     }
    //     else 
    // }

    cout<<"test"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--)
    solve();
    return 0;
}