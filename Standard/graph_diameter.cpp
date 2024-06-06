#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<vector<int>> g;
vector<int> visited;
vector<int> dist;
queue<int> bfsqueue;

void bfs(int nn)
{
    bfsqueue.push(nn);

    while(!bfsqueue.empty())
    {
        int tempval = bfsqueue.front();
        bfsqueue.pop();

        for(auto u: g[tempval])
        {
            if(dist[u]!=0)
            {
                dist[u] = dist[tempval]+1;
                bfsqueue.push(u);
            }
        }
    }
}

void dfs(int nn, int pp, int distval)
{
    cout<<" "<<nn;
    dist[nn] = distval;

    for(auto u: g[nn])
    {
        if(u!=pp)
        {
            dfs(u,nn, distval+1);
        }
    }

}


void solve()
{
    cin>>n;
    g.clear();
    dist.resize(n+1);
    g.resize(n+1);

    for(int i=0; i<n-1; i++)
    {
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    // start at node 1
    dfs(1,0,0);
    dist[0]=0;

    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<" "<<dist[i+1]<<endl;
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