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
    ll n;
    cin>>n;

    vector<ll> a(n,0);
    ll i;
    fr(i,0,n) cin>>a[i];

    ll maxoddval=-1;
    ll evencount=0, oddcount=0;

    sort(a.begin(),a.end());

    fr(i,0,n)
    {
        if(a[i]%2==0) evencount++;
        else
        {
            oddcount++;
            maxoddval = max(maxoddval, a[i]);
        }
    }

    if(evencount==n || oddcount==n)
    {
        cout<<0<<endl;
        return;
    }

    ll finalans=0;
    ll curroddval= maxoddval;

    ll tempval=0;

    fr(i,0,n)
    {
        if(a[i]%2==0)
        {
            if(a[i]<maxoddval)
            {
                finalans++;
                maxoddval +=a[i];
            }
            else
            {
                tempval=1;
                finalans = finalans + 2;
                maxoddval = maxoddval + a[i] + a[i];
                break;
            }
        }
    }

    if(tempval==0)
    {
        cout<<evencount<<endl;
        return;
    }
    else cout<<evencount+1<<endl;
    return;

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}