#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin>>n;

    vector<ll> a(n,0),b(n+1,0);

    for(ll i=0; i<n; i++) cin>>a[i];
    for (ll i = 0; i < n+1; i++)
        cin >> b[i];

    ll mindist=1e9, sumdist=0, mindistindx=0,caseval;
    ll target = b[n];

    for(ll i=0; i<n; i++)
    {
        if (a[i] == target || b[i]==target || (a[i]<=target && target<=b[i]) )
        {
            mindist = 0;
            mindistindx = i;
            caseval = 0;
            break;
        }

        ll val1 = abs(a[i]-target);
        ll val2 = abs(target-b[i]);
        ll val3 = abs(a[i]-b[i]);   

        ll cost1 = val1 + val2;
        ll cost2 = val1 + val3;
        ll cost3 = val2 + val3;

        ll tempval = min(cost1,cost2);
        tempval = min(tempval, cost3);


        if(tempval <= mindist)
        {
            if (tempval == mindist && val3==0) continue;
            mindist = tempval;
            mindistindx = i;
            caseval=1;

        }
    }

    for(ll i=0; i<n; i++)
    {
        ll val = abs(a[i] - b[i]);
        
        if(i!=mindistindx)
        {
            sumdist+=val;
        }
    }

    if(caseval==0)
    {
        sumdist += (1+abs(a[mindistindx] - b[mindistindx]));
    }
    else
    {
        sumdist += (mindist+1);
    }

    cout<<sumdist<<endl;
    //  cout<<caseval<<endl;
    // cout<<mindistindx<<mindist<<endl;
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