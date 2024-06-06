#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9 + 7;

void solve()
{
    int n,x;
    cin>>n>>x;

    vector<int> c(n,0);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(c.begin(),c.end());

    vector<int> dp(1e6+3,-1);

    dp[0]=1;

    for(int i=0; i<n; i++)
    {
        if(c[i]<=x)
        dp[c[i]]=1;
    }

    // cout<<"Here"<<endl;


    for(int i=1; i<=x; i++)
    {
        // cout<<"How many times"<<endl;
        ll sum=0;
        for(int j=0; j<n; j++)
        {
            int temp = i - c[j];

            if(temp>=0)
            {
                if(dp[temp]>=0)
                sum+=dp[temp];
            }
        }
        if(sum>0) dp[i] = sum%modval;
        
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