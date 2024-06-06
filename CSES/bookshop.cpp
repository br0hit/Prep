#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
    
void solve()
{
    int n,x;
    cin>>n>>x;

    vector<int> h(n+1,0);
    vector<int> s(n+1,0);

    for(int i=0; i<n; i++) cin>>h[i+1];
    for(int i=0; i<n; i++) cin>>s[i+1];

    vector<vector<int>> dp(x+1, vector<int>(n+1,0));

    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int val1 = dp[i][j-1];
            int val2;
            if(i>=h[j])
            {
                 val2 = s[j] + dp[i-h[j]][j-1];
            }
            else  val2 = -1;

            dp[i][j] = max(val1,val2);
        }
    }

    cout<<dp[x][n]<<endl;
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