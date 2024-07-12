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

int bfs(int startnode, vector<int> &visited, vector<int> &parent, vector<int> gr[])
{   
    int n = visited.size()-1;
    queue<int> qu;
    qu.push(startnode);
    visited[startnode]=1;

    while(!qu.empty())
    {
        if(visited[n]==1)
        {
            return 1;
        }
        int topnode = qu.front();
        qu.pop();

        for(auto u: gr[topnode])
        {
            if(!visited[u])
            {
                visited[u]=1;
                parent[u]=topnode;

                qu.push(u);
            }
        }
    }

    return 0;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<int> gr[n+1];

    int i;
    fr(i,0,m)
    {
        int val1,val2;
        cin>>val1>>val2;

        gr[val1].push_back(val2);
        gr[val2].push_back(val1);
    }

    vector<int> visited(n+1,0);
    vector<int> parent(n+1,0);

    int answer = bfs(1, visited, parent, gr);

    if(visited[n]==1)
    {
        stack<int> ans;
        ans.push(n);

        while(1)
        {
            int parentnode = parent[n];
            ans.push(parentnode);

            if(parentnode==1) break;
            n = parentnode;
        }

        cout<<ans.size()<<endl;
        while(!ans.empty())
        {
            cout << ans.top() << " ";
            ans.pop();
        } 

    }
    else
    {
        cout << "IMPOSSIBLE"<<endl;
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