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
    ll n,s,m;
    cin>>n>>s>>m;

    vector<pair<int,int>> intervals(n,{0,0});

    ll i;
    fr(i,0,n) cin>>intervals[i].F>>intervals[i].S;

    int start = intervals[0].F;

    if(start>=s)
    {
        cout<<"yes"<<endl;
        return;
    }

    for(int i=0; i<n-1; i++)
    {
        ll timegap = intervals[i+1].F - intervals[i].S;
        if(timegap>=s)
        {
            cout<<"yes"<<endl;
            return;
        }
    }

    if(m-intervals[n-1].S>=s)
    {
        cout << "yes" << endl;
        return;
    }

    cout<<"no"<<endl;
    return;
}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}