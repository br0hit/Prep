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

ll finddp(ll sum, ll rem);

void solve()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> c(n+1, 0);

    ll i;
    fr(i, 0, n) cin>>c[i];

    vector<vector<ll>> dp(x+1, vector<ll>(n+1,0));

    fr(i,1,x+1)
    {
        // cout<<i<<endl;
        ll j;
        fr(j,0,n)
        {
            // cout<<j<<" The values: ";
            ll tempans=0;
            ll k;

            // if(i-c[j]>0)
            // {
            //     dp[i][j] = dp[i-c[j]][j] + dp[i][j+1];
            // }
            // else if(i==c[j])
            // {
            //     dp[i][j] = 1;
            // }
            fr(k,j,n)
            {
                if(i>c[k])
                {
                    tempans+= dp[i-c[k]][k];
                    // cout << i << " "<<c[k] << " " << dp[i - c[k]][k];
                }
                else if(i==c[k])
                {
                    tempans+=1;
                }
                tempans = tempans % modval;
            }

            dp[i][j] = tempans;
            // cout<<"Final val"<<endl;
            // cout<<i<<" "<<j<<" "<<c[j]<<" "<<dp[i][j]<<endl;
        }
    }

    ll ans;
    // fr(i,0,n)
    // {
    //     if(c[i]<= x)
    //     {
    //         ans+= dp[x-c[i]][i];
    //     }
    // }

    cout<<dp[x][0]<<endl;
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