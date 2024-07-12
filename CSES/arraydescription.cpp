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
int i;

int modval = 1e9 + 7;

ll calculatedp(int index, int val, vector<ll>&x, int n)
{

}

void solve()
{
    ll n,m;
    cin>>n>>m;

    vector<ll> x(n,0);
    ll i;
    fr(i,0,n) cin>>x[i];

    vector<vector<ll>> dp(n+1, vector<ll>(m+1,-1));

    ll ans = calculatedp()

    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}