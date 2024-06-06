#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define ll long long
#define endl "\n"
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second

int modval = 1e9 + 7;

void solve()
{
    int x,n;
    cin>>x>>n;

    int i;
    vi p(n,0);
    fr(i,0,n) cin>>p[i];

    multiset<int> dist;
    set<int> vals;

    vals.insert(0);
    vals.insert(x);

    dist.insert(x);

    for(int i=0; i<n; i++)
    {
        auto upperbound = vals.upper_bound(p[i]);
        auto lowerbound = vals.upper_bound(p[i]);
        lowerbound--;

        int tempval = *upperbound - *lowerbound;

        //cout<<*upperbound-p[i]<<p[i]-*lowerbound<<p[i]<<endl;

        dist.erase(dist.find(tempval));
        dist.insert(p[i]-*lowerbound);
        dist.insert(*upperbound-p[i]);
        vals.insert(p[i]);

        int ans = *(--dist.end());

        cout<<ans<<" ";
    }


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin >> t; while (t--)
    solve();
    return 0;
}