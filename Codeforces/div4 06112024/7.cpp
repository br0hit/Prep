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

ll modval = 1e9 + 7;

ll fast_exp(ll base, ll exp, ll mod)
{
    ll res = 1LL;
    while (exp > 0)
    {   
        if (exp % 2 == 1)
            res = (res * base * 1LL) % mod;
        base = (base * base * 1LL) % mod;
        exp = exp / 2;
    }
    return res;
}

void solve()
{
    ll l,r,k;
    cin>>l>>r>>k;

    ll ans=0;
    ll maxdig = 9/k;
    ll powval = 1;
    ll i;
    ll templ = l;

    if(k>9 && l>0)
    {
        cout<<0<<endl;
        return;
    }
    // else if(k>9 && l==0)
    // {
    //     cout<<9<<endl;
    //     return;
    // }

    // while(templ--)
    // {
    //     powval = powval * (maxdig+1);
    //     if(powval>modval)
    //     powval = powval%modval;
    // }

    if(maxdig==1)
    {
        fr(i,l,r)
        {
            ans += powval<<i;
        }
    }

    powval = fast_exp(maxdig+1,templ,modval);
    powval *=maxdig;

    fr(i,l,r)
    {
        ans += powval;
        ans = ans%modval;
        powval *= ((maxdig+1));
        powval = powval%modval;
    }

    cout<<ans<<endl;


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