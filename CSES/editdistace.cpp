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

int solvedp(string &a, string &b, int len1, int len2, vector<vector<int>> &dp)
{   
    if(dp[len1][len2]!= -1) return dp[len1][len2];
    if (len1 == 0)
        return len2;
    if (len2 == 0)
        return len1;

    if(a[len1-1] == b[len2-1])
    {
        int ans = solvedp(a, b, len1 - 1, len2 - 1, dp);
        return ans;
    }

    // if(len1>len2)
    // {
    //     int ans = 1 + solvedp(a,b,len1-1,len2,dp);
    //     return dp[len1][len2] = ans;
    // }
    // else if(len2>len1)
    // {
    //     int ans = 1 + solvedp(a, b, len1 , len2-1 , dp);
    //     return dp[len1][len2] = ans;
    // }
    // else
    // {
        int val1 = 1 + solvedp(a, b, len1, len2 - 1, dp);
        int val2 = 1 + solvedp(a, b, len1 -1, len2, dp);
        int ans = 1 + solvedp(a, b, len1 -1 , len2 - 1, dp);

        ans = min(ans,val1);
        ans = min(ans,val2);

        return dp[len1][len2] = ans;
    // }

    return 1;
}

void solve()
{
    string a,b;
    cin>>a>>b;

    int len1=a.size();
    int len2=b.size();

    vector<vector<int>> dp(len1+1, vector<int>(len2+1,-1));

    int ans = solvedp(a,b,len1,len2,dp);

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