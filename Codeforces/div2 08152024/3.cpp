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


void solve()
{
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n,0);
    ll i;
    fr(i,0,n) cin>>a[i];

    sort(a.rbegin(),a.rend());

    ll asum=0;
    ll bsum = 0;

    fr(i,0,n)
    {
        if(i%2==0)
        {
            asum+=a[i];
        }
        else
        {
            ll tempval = a[i-1]-a[i];
            if(k>=tempval)
            {
                bsum+=a[i-1];
                k = k-tempval;
            }
            else
            {
                bsum+=a[i]+k;
                k=0;
            }
        }
    }

    cout<<asum-bsum<<endl;
    return;



}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}