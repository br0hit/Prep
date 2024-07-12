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
    ll n;
    cin>>n;

    vector<ll> a(n,0);
    ll i;
    fr(i,0,n) cin>>a[i];

    ll sumtillnow=0;
    ll maxval=-1;

    ll count=0;

    fr(i,0,n)
    {
        if(a[i]>maxval) maxval = a[i];

        sumtillnow+=a[i];

        if(maxval==sumtillnow-maxval)
        {
            count+=1;
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