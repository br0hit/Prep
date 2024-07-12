#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modval = 1e9 + 7;

ll calculateval(ll i, ll j, vector<vector<ll>> &dp, vector<vector<ll>> &ready, vector<vector<char>> &matrix, ll n)
{
    if (i < 0 || i > n || j < 0 || j > n)
        return 0LL;

    if (ready[i][j] == 1)
        return dp[i][j];

    if (i == n && j == n)
        return 1LL;

    ll tempsum;

    // if(matrix[i+1][j]!= '*') tempsum += dp[i+1][j];
    // if (matrix[i][j+1] != '*') tempsum += dp[i][j+1];

    tempsum = calculateval(i + 1, j, dp, ready, matrix, n) + calculateval(i, j + 1, dp, ready, matrix, n);

    dp[i][j] = tempsum % modval;
    ready[i][j] = 1;
    // cout<<ready[i][j] << " " << dp[i][j] << endl;

    return tempsum;
}

void solve()
{
    ll n;
    cin >> n;

    vector<vector<char>> matrix(n + 2, vector<char>(n + 2, '\0'));

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<vector<ll>> dp(n + 2, vector<ll>(n + 2, 0LL));
    vector<vector<ll>> ready(n + 2, vector<ll>(n + 2, 0));

    for (ll i = 1; i <= n+1; i++)
    {
        for (ll j = 1; j <= n+1; j++)
        {
            if(i>n || j>n)
            {
                dp[i][j] = 0LL;
                ready[i][j] = 1;
                continue;
            }

            if (matrix[i][j] == '*')
            {
                dp[i][j] = 0LL;
                ready[i][j] = 1;
            }
        }
    }

    if (matrix[n][n] == '*')
    {
        cout << 0 << endl;
        return;
    }

    dp[n][n] = 1LL;
    ready[n][n] = 1;
    int curr=0;

    // for(int i=n-1; i>=1; i--)
    // {
    //     if(curr==0 && matrix[n][i]=='.')
    //     {
    //         ready[n][i]=1;
    //         dp[n][i]=1LL;
    //     }
    //     else
    //     {
    //         ready[n][i] = 1;
    //         dp[n][i] = 0LL;
    //         curr=1;
    //     }
    // }

    // curr=0;

    // for (int i = n - 1; i >= 1; i--)
    // {
    //     if (curr == 0 && matrix[i][n] == '.')
    //     {
    //         ready[n][i] = 1;
    //         dp[n][i] = 1LL;
    //     }
    //     else
    //     {
    //         ready[i][n] = 1;
    //         dp[i][n] = 0LL;
    //         curr=1;
    //     }
    // }

    if (matrix[n - 1][n] == '.')
    {
        dp[n - 1][n] = 1LL;
        ready[n - 1][n] = 1;
    }

    if (matrix[n][n - 1] == '.')
    {
        dp[n][n - 1] = 1LL;
        ready[n][n - 1] = 1;
    }

    ll ans = calculateval(1, 1, dp, ready, matrix, n)%modval;

    cout << ans << endl;
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