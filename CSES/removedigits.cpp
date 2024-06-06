#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin>>n;

    vector<int> dp(n+1,1e9);
    for(int i=1; i<=9; i++) dp[i] = 1;

    for(int i=10; i<=n; i++)
    {
        int minval = 1e9;
        int dup = i;
        while(dup>0)
        {
            int temp = dup%10;
            dup /=10;
            minval = min(minval, 1+dp[i-temp]);
        }

        dp[i] = minval;
    }

    cout<<dp[n]<<endl;
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