#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin>>n;
    ll k; cin>>k;

    vector<ll> a(n,0);
    for(int i=0; i<n; i++) cin>>a[i];

    ll frontattack,backattack;

    if(k%2==0LL) frontattack = k/2LL; 
    else frontattack = (k/2LL) + 1LL;
    backattack = k/2LL;

    ll frontsum=0LL,backsum=0LL;
    ll totalsum=0LL;

    for(int i=0; i<n; i++)
    {
        totalsum+=a[i];
    }

    if(k>=totalsum)
    {
        cout<<n<<endl;
        return;
    }

    int fi,bi;

    for(int i=0; i<n; i++)
    {
        frontsum+=a[i];
        if(frontsum>frontattack)
        {
            fi = i;
            break;
        }
    }

    for(int i=n-1; i>=0; i--)
    {
        backsum+=a[i];
        if(backsum>backattack)
        {
            bi = i;
            break;
        }
    }

    int total = fi + (n-1) - bi;

    cout<<total<<endl;

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