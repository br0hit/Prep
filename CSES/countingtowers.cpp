#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define endl '\n'
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second
ll modval = 1e9 + 7;


void solve()
{
    ll t;
    cin>>t;

    vector<ll> tempn(t,0);
    ll maxn = -1;

    for(ll i=0; i<t; i++) 
    { 
        cin>>tempn[i];
        maxn = max(maxn, tempn[i]);
    }

    // ll maxn = *max_element(tempn.begin(), tempn.end());
    //cout<<maxn<<endl;

    vector<ll> dpa(maxn+1,0);
    vector<ll> dpb(maxn+1,0);

    dpa[1] = 1;
    dpb[1] = 1;

    for(ll i=2; i<=maxn; i++)
    {
        dpa[i] = (2*dpa[i-1]%modval + dpb[i-1])%modval;
        dpb[i] = (4*dpb[i-1]%modval + dpa[i-1])%modval;
        
    }

    for(ll i=0; i<t; i++)
    {
        ll result = (dpa[tempn[i]] + dpb[tempn[i]])%modval;
        // cout <<tempn[i]<<" "<<result<< endl;
        cout <<result << endl;
    }

    return;

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       solve();
}