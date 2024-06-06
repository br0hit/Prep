#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> c(n,0);

    for(int i=0; i<n ; i++)
    {
        cin>>c[i];
    }

    vector<vector<int>> dp(x+1, vector<int>(n+1,0));

    for(int i=1; i<=x; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j] = 1 + dp[i-c[j]][j] + dp[i][j+1];
        }
    }
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