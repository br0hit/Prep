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

ll solvedp(ll totalw, ll n, vector<ll> w, vector<ll> v, vector<vector<ll>> &dp)
{
    // cout<<totalw<<" "<<n<<" "<<w[n]<<endl;
    if (totalw < 0)
        return -1e9;

    if(dp[n][totalw]!=-1) return dp[n][totalw];


    if(n<=0) return 0;
    if(totalw==0) return 0;

    ll ans;

    ll val1 = solvedp(totalw, n - 1, w, v, dp);
    ll val2;
    val2 = solvedp(totalw - w[n], n - 1, w, v, dp) + v[n];

    ans = max(val1,val2);

    return dp[n][totalw] = ans; 
}

void solve()
{
    ll n,totalw;
    cin>>n>>totalw;

    ll i;
    vector<ll> w(n+1,0),v(n+1,0);

    fr(i,1,n+1)
    {
        cin>>w[i]>>v[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(totalw+1,-1));

    ll ans =  solvedp(totalw,n,w,v,dp);

    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<= totalw; j++)    
        {
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }

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