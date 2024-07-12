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

ll modval = 1e9;

void solve()
{
    int n;
    cin>>n;

    vector<ll> k(n,0);
    fr(i,0,n) cin>>k[i];

    if(n==1)
    {
        cout<<1<<endl;
        return; 
    }

    ll prod=1LL;
    ll prefixsum=0LL;
    vector<ll> prefix(n,0);
    prefix[n-1] = k[n-1];

    for(int i=n-2; i>=0; i--)
    {
        prefix[i] = prefix[i+1] + k[i];
    }

    ll sum;

    fr(i,0,n)
    {
        sum+=k[i];
        prod *= k[i];
        prod = prod%modval;
        if(i<n-1) prefixsum+=k[i]*prefix[i+1];
    }

    ll val=0LL;

    fr(i,0,n)
    {
        val = val + prod/k[i];
        val = val%modval;
    }

    // cout<<prod<<" "<<prefixsum<<" "<<val<<endl;

    if(val >= prod) 
    {
        cout<<-1<<endl;
        return;
    }
    else
    {
        fr(i,0,n)
        {
            cout<<prod/k[i]<<" ";
        }
        cout<<endl;
    }


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t; while (t--)
    solve();
    return 0;
}