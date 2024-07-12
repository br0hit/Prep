#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll  long long
#define endl "\n"
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second
int i;

int modval = 1e9 + 7;

int check(ll x, set<ll> cval, ll rem, unordered_map<ll,ll> mp)
{
    unsigned long long dmgval=0;

    for(auto u: cval)
    {
        dmgval += (x/u)*mp[u];
        if(dmgval>= rem) return 1;
    }

    return 0;

}

void solve()
{
    ll h,n;
    cin>>h>>n;

    vector<ll> a(n+1,0),c(n+1,0);
    ll i;
    fr(i,1,n+1) cin>>a[i];
    fr(i,1,n+1) cin>>c[i];

    unordered_map<ll,ll> dmg;
    set<ll> cval;
    ll intial =0;

    fr(i,1,n+1)
    {
        intial+=a[i];
        dmg[c[i]]+=a[i];
        cval.insert(c[i]);
    }

    ll rem = h-intial;
    // cout<<h<<" "<<intial<<" "<<rem<<endl;
    if(rem<=0)
    {
        cout<<1<<endl;
        return;
    }

    ll turn=*cval.begin();
    ll gcdval=turn;
    for(auto u: cval)
    {
        gcdval = gcd(gcdval, u);
    }

    ll lo=1;
    ll hi=1e18;
    ll ans=1;

    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        
        if(check(mid, cval, rem,dmg))
        {
            ans = mid;
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }

    cout<<ans+1<<endl;
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
