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

    vector<int> a(n,0);
    int i;
    fr(i,0,n) cin>>a[i];

    vector<int> dp;
    dp.push_back(a[0]);
    // dp[0] = 1;

    fr(i,1,n)
    {
        int len = dp.size();
        int index = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();

        if(index == len)
        {
            dp.push_back(a[i]);
        }
        else
        {
            dp[index] = a[i];
        }

        int k;
        //fr(k,0,dp.size()) cout<<dp[k].F<<" "<<dp[k].S<<" ";
        //  cout<<endl;
        // fr1(j,i)
        // {
        //     if(a[j]<a[i])
        //     {
        //         int temp = dp[j]+1;
        //         dp[i] = max(dp[i],temp);
        //     }
        // }
    }

    int maxval= dp.size();


    // fr(i,0,n) {  maxval = max(maxval,dp[i]); }
    cout<<endl<<maxval<<endl;
    return;
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