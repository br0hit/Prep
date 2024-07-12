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

ll modval = 1e9 + 7;

void solve()
{
    ll n,x;
    cin>>n>>x;

    vector<ll> c(n,0);  

    ll i;
    fr(i,0,n) cin>>c[i];

    vector<ll> dp(x+1,-1);
    dp[0] = 1;

    fr(i,1,x+1)
    {
        ll temp=0;
        ll j;
        fr(j,0,n)
        {
            if(i-c[j]>=0)
            {
                //cout<<i-c[j]<<" ";
                if (dp[i - c[j]] >= 0)
                {
                    // cout << dp[i - c[j]]<<" ";
                    temp += (dp[i - c[j]]);
                }
            }
        }
        if(temp==0) temp=-1;
        else temp = temp%modval;
        //cout<<i<<" "<<temp<<endl;
        dp[i] = temp;
    }

    if(dp[x]==-1) dp[x]=0;
    cout<<dp[x]<<endl;


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