#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 3)
    {
        cout << "YES" << endl;
        return;
    }

    vector<vector<int>> dp(n, vector<int>(2,0));

    dp[2][0] = 
    dp[2][1] = 



    for(int i=3; i<n; i++)
    {
        if(dp[i-1][0])
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}