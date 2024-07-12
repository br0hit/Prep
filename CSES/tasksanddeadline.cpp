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
    ll n;
    cin>>n;
    vector<pair<ll,ll>> v(n,{0,0});
    ll i;
    fr(i,0,n) cin>>v[i].F>>v[i].S;
    fr(i, 0, n) v[i].S = -v[i].S;

    sort(v.begin(),v.end());

    ll time=0;
    ll reward=0;
    fr(i,0,n)
    {
        time+=v[i].F;
        reward+=(-v[i].S-time);
    }

    cout<<reward<<endl;


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