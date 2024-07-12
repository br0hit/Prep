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

void solve()
{
    ll n,l,r;
    cin>>n>>l>>r;

    vector<ll> a(n,0);
    vector<ll> presum(n,0);
    ll i; fr(i,0,n) cin>>a[i];

    ll tempval=0;
    ll count=0;
    ll curri=0;

    for(int i=0; i<n; i++)
    {
        tempval+=a[i];
        presum[i] = tempval;

        

        if(tempval>=r)
        {
    
        }
    }
    cout<<count<<endl;


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