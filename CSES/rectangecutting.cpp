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

int solvedp(int x, int y, vector<vector<int>> &dp)
{
    if(dp[x][y]!=-1) return dp[x][y];

    if(y>x)
    {
        dp[x][y] = 1 + solvedp(x,y-x,dp);
    }
    else dp[x][y] = 1+ solvedp(x-y,y,dp);

    return dp[x][y];
}

void solve()
{
    int a,b;
    cin>>a>>b;

    vector<vector<int>> dp(a+1, vector<int>(b+1,-1));

    int i,j;

    fr(i,1,a+1) fr(j,1,b+1)
    {
        if(i==j) dp[i][j]=0;
    }

    // fr(i, 1, a + 1) fr(j, 1, b + 1)
    // {
    //     if(dp[i][j]==-1)
    //     {
    //         if(i>j)
    //         {
    //             dp[i][j] = 1 + dp[i-j][j];
    //         }
    //         else
    //         {
    //             dp[i][j] = 1 + dp[i][j-i];
    //         }
    //     }
    // }

    cout<<solvedp(a,b,dp)<<endl;
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