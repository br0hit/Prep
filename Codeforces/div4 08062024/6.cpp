#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll unsigned long long
#define endl '\n'
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second
ll modval = 1e9 + 7;

ll nck(ll n, ll k)
{
    ll num = 1, den = 1;

    for (ll i = 0; i < n - k; i++)
    {
        num = (num * (k + i + 1));
        den = (den * (i + 1));

        if (num % den == 0)
        {
            num = (num / den)%modval;
            den = 1;
        }
    }

    ll finaltotalval = (num / den) % modval;

    return finaltotalval;
}


void solve()
{
    ll n,k;
    cin>>n>>k;

    ll zerocount=0;
    ll onecount = 0;

    vector<int> a(n,0);
    ll i; 
    fr(i,0,n)
    {
        cin>>a[i];

        if(a[i]==0) zerocount++;
        else onecount++;
    }




    if(onecount<((k/2)+1))
    {
        cout<<0<<endl;
        return;
    }

    ll val = (k/2)+1;

    ll intialval = nck(n,k);

    if(zerocount<val)
    {
        cout<<intialval<<endl;
        return;
    }

    if(onecount<val)
    {
        cout<<0<<endl;
        return;
    }

    // for(ll i=val; i<= zerocount; i++)
    // {
    //     ll subract = ((nck(zerocount,i)%modval)*(nck(onecount,k-i)%modval))%modval;
    //     //cout<<subract<<endl;
    //     intialval -= subract;
    //     if(intialval<0) intialval += modval;
    // }

    ll totalval=0;
    for (ll i = val; i <= min(k, onecount) ; i++)
    {
        if(i>onecount) break;
        ll add = ((nck(onecount, i) % modval) * (nck(zerocount, k - i) % modval)) % modval;
        // cout<<subract<<endl;
        totalval += add;
        totalval = totalval%modval;
    }
    cout<<totalval<<endl;
    return;

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}