#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define endl "\n"
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second

int modval = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;

    vi h(n+1,0);
    int i;
    fr(i,1,n+1) cin>>h[i];

    if(n==1)
    {
        cout<<0<<endl;
        return;
    }

    vi dp(n+1,1e9);
    dp[1] = 0;

    fr(i,2,n+1)
    {
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
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