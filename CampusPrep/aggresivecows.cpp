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
int modval = 1e9 + 7;

int calcualte(vector<ll> pos, ll val, ll c)
{
    auto prev = pos.begin();
    ll prevpos=pos[0];
    for(ll i=1; i<c; i++)
    {
        ll val1 = prevpos + val;
    

        auto u = lower_bound(prev, pos.end(), val1);
        if(u==pos.end()) return 0;

        // cout<<val1<<" "<<*u<<endl;

        prev = u;
        prevpos = *u;
    }
    return 1;
}


void solve()
{
    ll n,c;
    cin>>n>>c;

    vector<ll> pos(n,0);
    ll i;

    for(i=0; i<n; i++)
    {
        cin>>pos[i];
    }

    sort(pos.begin(),pos.end());

    cout<<pos.end()-pos.begin()<<endl;
    

    ll left =0;
    ll right = 1e9;
    ll ans=1;

    while(left<=right)
    {
        ll mid = (left+right)/2;
        // cout<<left<<right<<" "<<mid<<endl;

        if(calcualte(pos,mid, c))
        {
            left = mid+1;
            ans = mid;
            // cout<<"here"<<mid;
        }
        else
        {
            right = mid-1;
        }
    }

    cout<<ans<<endl;

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}