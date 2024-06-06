#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> topo;

void  dfs(int node, vector<int> &visited, vector<vector<int>> &graph)
{
    visited[node] = 1;
    cout<<"current dfs node"<<node<<endl;
    // cout<<"Final answer"<<graph[node].size()<<endl;
    for (auto u: graph[node])
    {
        if (visited[u]==0)
        {
            dfs(u,visited,graph);
        }
    }

    topo.push_back(node);
    cout<<"Reached here for node "<<node<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;
    // while (t--)
        // solve();

    int numCourses = 2;
    vector<vector<int>> prerequisites;

    prerequisites.push_back(vector<int>{1,0});
    prerequisites.push_back(vector<int>{0,1});

    vector<vector<int>> g;
    vector<int> visited;
    visited.assign(numCourses, 0);
    g.resize(numCourses);

    for (int i = 0; i < prerequisites.size(); i++)
    {
        g[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    cout<<endl;

    for(int i=0; i<numCourses; i++)
    {
        cout<<i<<" "<<g[i].size()<<endl;
    }

    
    cout<<"Got here atleast"<<endl;

    int ans = 0;

    for (int i = 0; i < numCourses; i++)
    {
        if (visited[i] == 0)
        {
            cout << "Current graph getting checked" << i << endl;

            dfs(i, visited, g);
        }
    }

    for(int i=0; i<topo.size(); i++)
    {
        cout<<topo[i]<<" ";
    }

}