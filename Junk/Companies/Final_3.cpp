#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define endl '\n'
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second

string reverse(string input)
{
    int l, r = input.size() - 1;
    for (l = 0; l < r; l++, r--)
    {
        char temp = input[l];    
        input[l] = input[r];
        input[r] = temp;
    }
    return input;
}

ll dp[200001][5][2];

ll solve(int i, string &s, int mx, int c)
{
    int n = s.size();

    if (i == n)
    {
        return 0;
    }
        
    
    if (dp[i][mx][c] != -1)
    {
        return dp[i][mx][c];
    }
        

    ll ans = -1e18;

    ll val[5] = {1, 10, 100, 1000, 10000};

    int tempval = s[i] - 'A';

    if (c)
    {
        if (mx > (tempval))
            ans = -val[(tempval)];

        else
            ans = val[(tempval)];

        ans = ans + solve(i + 1, s, max(mx, tempval), c);

        return dp[i][mx][c]=ans;
    }

    for (int j = 0; j < 5; j++)
    {
        ll temp = 0;
        if (mx > j)
            temp = -val[j];
        else
            temp = val[j];

        temp += solve(i + 1, s, max(mx, j), tempval != j);
        ans = max(ans, temp);
    }

     return dp[i][mx][c] = ans;
}

int  main()
{
    string s;
    cin >> s;


    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
            
    }

    reverse(s.begin(),s.end());

    ll val = solve(0, s, 0, 0);

    cout << val;
}