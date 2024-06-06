#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<int,int>>> g;

void dijkstras(int node,  vector<int>& dist)
{
    int numnodes = dist.size()-1;
    for(int i=1; i<=numnodes; i++) dist[i] = 1e9;

    dist[node] = 0;
    priority_queue<pair<int,int>> q;
    vector<int> visited(numnodes+1,0);
    q.emplace(0,node);

    int mainnode = node;

    while(!q.empty())
    {
        pair<int, int> topelement = q.top();
        int topnode = topelement.second;
        int topnodedistance = -topelement.first;
        if(visited[topnode]==1)
        {
            q.pop();
            continue;
        }
        visited[topnode]=1;
        cout<<"node"<<topnode<<endl;
        q.pop();

        for(auto u: g[topnode])
        {
            int disttomain = u.second + topnodedistance;
            if(disttomain<dist[u.first])
            {
                dist[u.first] = disttomain;
            }
            cout<<u.first<<" "<<disttomain<<endl;
            q.push({-disttomain,u.first});
        }
    }

}

void bellmanford(int node, vector<int> &dist)
{
    int n = dist.size()-1;
    for(int i=1; i<n+1; i++) dist[i] = 1e9;
    dist[node] = 0;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    g.clear();
    g.resize(n+1);

    for(int i=0; i<m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        // g[a].emplace_back(b,c);
        g[a].emplace_back(b,c);
        g[b].push_back(make_pair(a,c));
    }

    for(int i=1; i<n+1; i++)
    {
        for(int j=0; j<g[i].size(); j++)
        {
            cout<<i<<" "<<g[i][j].first<<","<<g[i][j].second<<"  ";
        }
        cout<<endl;
    }

    vector<int> dist(n+1,0);
    cout<<"Calling algo"<<endl;

    dijkstras(1,dist);
    cout<<"End of algo"<<endl;
    for(int i=1; i<n+1; i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }






}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

/*
5 6
1 2 5
1 4 9
1 5 1
2 3 2
3 4 6
4 5 2
*/