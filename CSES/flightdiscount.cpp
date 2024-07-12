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
    ll n,m;
    cin>>n>>m;

    ll i;
    vector<pair<ll,ll>> gr[n+1];
    fr(i,0,m)
    {
        ll val1,val2,val3;
        cin>>val1>>val2>>val3;

        gr[val1].push_back({val2,val3});
        // gr[val1].push_back({n+1,val3/2});
        // gr[n+1].push_back({val2,0});
    }

    priority_queue<pair<ll,ll>> qu;
    vector<ll> visited(n+1,0);
    vector<ll> dist(n+1, 1e18);
    vector<int> direct(n+1,0);
    vector<pair<ll,ll>> parent(n+1,{0,0});
    qu.push({0,1});

    for(auto u: gr[1])
    {
        direct[u.F] = u.S; 
    }
    // for(auto u: gr[1])
    // {
    //     dist[u.F] = u.S;
    // }

    while(!qu.empty())
    {
        auto val = qu.top();
        qu.pop();
        if(visited[val.S]==1) continue;
        dist[val.S] = -val.F;
        if(dist[val.S]==direct[val.S])
        {
            parent[val.S] = {1,dist[val.S]};
        }

        visited[val.S]=1;

        for(auto u: gr[val.S])
        {
            ll newdist = dist[val.S] + u.S;
            if(newdist<dist[u.F])
            {
                parent[u.F] = {val.S,u.S};
            }
            qu.push({-newdist,u.F});
        }
    }

    // fr(i, 1, n + 1) cout << dist[i] << " ";
    // return;
    ll endnode = n;
    ll maxdist=-1,totaldist=0;
    while(1)
    {
        // cout<<endnode<<" "<<parent[endnode].S<<endl;
        totaldist += parent[endnode].S;
        if(parent[endnode].S> maxdist)
        {
            maxdist = parent[endnode].S;
        }
        endnode = parent[endnode].F;
        if (endnode == 1)
            break;
    }

    ll ans = totaldist - maxdist + maxdist/2;
    cout<<ans<<endl;
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