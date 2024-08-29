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
    ll i; fr(i,0,n) cin>>a[i];

    if(n==1)
    {
        cout<<a[0]<<endl;
        return;
    }



    sort(a.begin(),a.end());

    ll curr_k=0;

    ll maxval = a[n-1];
    ll maxminus1 = a[n-2];

    for(int j=0; j<k; j++)
    {
        ll tempval = maxval + j;
        //cout<<tempval<<endl;
        ll mult = (tempval-maxminus1)/k;

        int cond=1;

        if(mult%2==0)
        {
            for(int i=n-3; i>=0; i--)
            {
                ll multval1 = (tempval - a[i])/k;
                if(multval1%2==1)
                {
                    // cout<<a[i]<<endl;
                    // cout<<-1<<endl;
                    cond=0;
                    break;
                } 
            }

            if(cond==1) 
            {
                cout<<tempval<<endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    return;
}   


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}