#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    int modval = 1e9 + 7LL;

    vector<ll> dp(n+1, 1LL);

    for (int i = 2; i <= n; i++)
    {
        if(i<=6)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                dp[i] += dp[j];
            }
        }
        else
        {
            dp[i]=0;
            for(int j=1; j<=6; j++)
            {
                dp[i]+= dp[i-j];
            }
        }

        dp[i] = dp[i]%modval;

    }

    int ans = dp[n]%modval;
    cout<<ans<<endl;
    
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
