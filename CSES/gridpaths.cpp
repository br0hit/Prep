#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calculateval(int i, int j, vector<vector<ll>> &dp, vector<vector<int>> &ready, vector<vector<char>> matrix, int n)
{
    cout<<i<<" "<<j<<" "<<ready[i][j]<<endl;
    ll modval = 1e9 + 7;

    if (i < 0 || i > n || j < 0 || j > n)
        return 0LL;

    if (ready[i][j] == 1) return dp[i][j];


    if(i==n && j==n) return 1LL;

    ll tempsum=0LL;

    // if(matrix[i+1][j]!= '*') tempsum += dp[i+1][j];
    // if (matrix[i][j+1] != '*') tempsum += dp[i][j+1];

    if(i+1>n)
    {
        tempsum = calculateval(i, j + 1, dp, ready, matrix, n);
    }
    else if(j+1>n)
    {
        tempsum = calculateval(i+1, j, dp, ready, matrix, n);
    }
    else
        tempsum = calculateval(i + 1, j, dp, ready, matrix, n) + calculateval(i, j + 1, dp, ready, matrix, n);

    // tempsum = val1 + val2;

    dp[i][j] = tempsum % modval;
    ready[i][j] = 1;
    // cout<<ready[i][j] << " " << dp[i][j] << endl;

    return dp[i][j];

}

void solve()
{
    int n=1000;
    // cin>>n;

    vector<vector<char>> matrix(n+1, vector<char>(n+1,'.'));

    // for(int i=1; i<=n; i++)
    // {
    //     for(int j=1; j<=n; j++)
    //     {
    //         cin>>matrix[i][j];
    //     }
    // }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 2, 0LL));
    vector<vector<int>> ready(n + 1, vector<int>(n + 2, -1));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(matrix[i][j]=='*')
            {
                dp[i][j]=0LL;
                ready[i][j]=1;
            }
        }
    }

    if(matrix[n][n]=='*')
    {
        cout<<0<<endl;
        return;
    }

    matrix[n][n] = 0;
    ready[n][n] = 1;

    if(matrix[n-1][n]=='.')
    {
        dp[n-1][n] = 1LL;
        ready[n-1][n] =1;
    }

    if (matrix[n ][n -1 ] == '.')
    {
        dp[n ][n -1] = 1LL;
        ready[n ][n -1 ] = 1;
    }

    ll ans = calculateval(1,1,dp,ready, matrix,n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<ready[i+1][j+1]<<" ";
        }
        cout<<endl;
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