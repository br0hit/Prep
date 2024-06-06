#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,x;
    cin>>n>>x;

    vector<int> c(n,0);
    for(int i=0; i<n; i++) cin>>c[i];

    // int ans=0;
    // for(int i=0; i<n; i++)
    // {
    //     if(c[i]>x)
    //     {
    //         ans=1;
    //         break;
    //     }
    // }

    // if(ans==0)
    // {
    //     cout << -1 << endl;
    //     return;
    // }
    // cout << "jfsajd" << endl;

    vector<int> dp(1e6,1e7);
    // cout << "jfsajdfejjsfk" << endl;

    for(int i=0; i<n; i++)
    {
        dp[c[i]]=1;
    }
    // cout<<"declared"<<endl;

    for(int i=1; i<=x; i++)
    {
        int minval=1e9;
        if(dp[i]!=1)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - c[j] > 0)
                {
                    int tempval = 1 + dp[i - c[j]];
                    minval = min(minval, tempval);
                }
            }

            dp[i] = minval;
        }



    }

    if(dp[x]==1e9) dp[x]=-1;

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