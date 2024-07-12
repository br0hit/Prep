#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second

#define endl "\n"

int i;
int modval = 1e9 + 7;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n,0);
    ll i;
    fr(i,0,n) cin>>a[i];

    vector<ll> suffix(n,0);
    suffix[n-1] = a[n-1];

    fr1(i,n-2)
    {
        //cout<<"INSIDE";
        suffix[i] = suffix[i+1] + a[i];
       //  cout<<i<<" "<<a[i]<<" "<<suffix[i]<<endl;
    }

    // fr(i,0,n) cout<<i<<" "<<suffix[i]<<endl;

    ll c=0;

    fr(i,0,n-1)
    {
        c+=a[i];
        // cout<<i<<" "<<suffix[i+1]<<endl;
        
        if(suffix[i+1]>0)
        {
            c = abs(c);
        }                        

    }
    c+=a[n-1]; 
    cout<<abs(c)<<endl;
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