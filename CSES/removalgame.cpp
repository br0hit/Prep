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

ll finddp(ll l, ll r, vector<vector<ll>> &dp, vector<ll> &x, ll &totalsum )
{
    // cout<<l<<" "<<r<<endl;
    if(dp[l][r]!=1e18) return dp[l][r];

    if(l==r) return dp[l][l] = x[l];

    ll ans=0;

    ll tval1 = totalsum - x[l];
    ll tval2 = totalsum - x[r];
    ll val1 = finddp(l + 1, r, dp, x, tval1);
    ll val2 = finddp(l, r - 1, dp, x, tval2);

    if (val1>val2)
    {
        ans = totalsum - val2;
    }
    else
        ans = totalsum - val1;

    return dp[l][r] = ans;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll> x(n+1,0);

    ll i;
    fr(i,1,n+1) cin>>x[i];

    //cout << "Reached here" << endl;

    ll totalsum=0;
    fr(i,1,n+1) totalsum+=x[i];

    vector<vector<ll>> dp(n+1, vector<ll>(n+1,1e18));

    ll ans = finddp(1,n,dp, x, totalsum);

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