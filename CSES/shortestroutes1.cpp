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

int modval = 1e9 + 7;

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<pair<ll,ll>> gr[n + 1];
    vector<ll> dist(n+1,-1);
    ll i;
    fr(i, 0, m)
    {
        ll val1, val2,val3;
        cin >> val1 >> val2>>val3;

        gr[val1].push_back({val2,val3});
    }


    priority_queue<pair<ll,ll>> pq;
    pq.push({0,1});

    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();  
        if(dist[top.second]!=-1) continue; 
        dist[top.second] = -top.first;
        // cout<<"Value added "<<top.second<<" "<<-top.first<<endl;

        for(auto u: gr[top.second])
        {
            ll newdist = dist[top.second]+u.second;
            // cout<<u.first<<" "<<newdist<<endl;
            pq.push({-newdist, u.first});
        }
    }

    fr(i,1,n+1) cout<<dist[i]<<" ";

    // fr(i,0,m)
    // {

    // }


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