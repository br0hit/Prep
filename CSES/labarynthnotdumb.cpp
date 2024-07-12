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

int dfs(int x, int y, vector<vector<int>> &visited, vector<vector<char>> adj, vector<char> &path, int endx, int endy)
{
    visited[x][y]=1;

    if(x==endx && y==endy)
    {
        return 1;
    }

    if(visited[x+1][y]==0 && adj[x+1][y]=='.')
    {
        path.push_back('D');
        int ans = dfs(x+1,y,visited,adj,path,endx,endy);
        if(ans==1) return 1;
        else path.pop_back();
    }
    if (visited[x ][y+1] == 0 && adj[x ][y+1] == '.')
    {
        path.push_back('R');
        int ans = dfs(x , y+1, visited, adj, path, endx, endy);
        if(ans==1) return 1;
        else path.pop_back();

    }
    if (visited[x - 1][y] == 0 && adj[x - 1][y] == '.')
    {
        path.push_back('U');
        int ans = dfs(x - 1, y, visited, adj, path, endx, endy);
        if (ans == 1)
            return 1;
        else
            path.pop_back();
    }
    if (visited[x][y-1] == 0 && adj[x][y-1] == '.')
    {
        path.push_back('L');
        int ans = dfs(x, y-1, visited, adj, path, endx, endy);
        if (ans == 1)
            return 1;
        else
            path.pop_back();
    }

    return 0;
}

int bfs(int startx, int starty, vector<vector<int>> &visited, vector<vector<pair<int,int>>> &parent, vector<vector<char>> adj, vector<char> &path, int endx, int endy)
{
    queue<pair<int,int>> qu;
    qu.push({startx,starty});
    visited[startx][starty]=1;

    while(!qu.empty())
    {
        if(visited[endx][endy]==1)
        {
            return 1;
        }
        auto u = qu.front();
        qu.pop();

        int x = u.first;
        int y = u.second;

        if (visited[x][y - 1] == 0 && adj[x][y - 1] == '.')
        {
            qu.push({x,y-1});
            visited[x][y-1] =1;
            parent[x][y-1]= {x,y};
        }
        if (visited[x][y + 1] == 0 && adj[x][y + 1] == '.')
        {
            qu.push({x, y + 1});
            visited[x][y + 1] = 1;
            parent[x][y + 1] = {x, y};
        }
        if (visited[x+1][y] == 0 && adj[x+1][y] == '.')
        {
            qu.push({x+1, y});
            visited[x+1][y] = 1;
            parent[x+1][y] = {x, y};
        }
        if (visited[x-1][y] == 0 && adj[x-1][y] == '.')
        {
            qu.push({x-1, y});
            visited[x-1][y] = 1;
            parent[x-1][y] = {x, y};
        }
    }

    return 0;
}

    void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> adj(n + 2, vector<char>(m + 2, '\0'));
    int i, j;
    int startx,starty,endx,endy;
    fr(i, 1, n + 1)
    {
        fr(j, 1, m + 1)
        {
            cin >> adj[i][j];
            if(adj[i][j]=='A')
            {
                startx = i;
                starty = j;
            }
            if(adj[i][j]=='B')
            {
                endx = i;
                endy=j;

                adj[i][j]='.';
            }
        }
    }

    vector<char> path;
    vector<vector<int>> visited(n+2, vector<int>(m+2,0));
    vector<vector<pair<int,int>>> parent(n+2, vector<pair<int,int>>(m+2,{0,0}));

    // int count = dfs(startx, starty, visited, adj, path, endx, endy);
    int countbrain = bfs(startx, starty, visited, parent, adj, path, endx, endy);
    stack<char> answer;

    if(visited[endx][endy]==1)
    {
        cout<<"YES"<<endl;
        while(1)
        {
            int parentx = parent[endx][endy].first;
            int parenty = parent[endx][endy].second;


            if(parentx == endx && parenty>endy) answer.push('L');
            if (parentx == endx && parenty < endy)
                answer.push('R');
            if (parentx > endx && parenty == endy)
                answer.push('U');
            if (parentx < endx && parenty == endy)
                answer.push('D');

            if (parentx == startx && parenty == starty)
            {
                break;
            }

            endx = parentx;
            endy = parenty;
        }
        cout<<answer.size()<<endl;
        // fr(i,0,path.size()) cout<<path[i];
        while(!answer.empty())
        {
            cout<<answer.top();
            answer.pop();
        }
    }
    else cout<<"NO"<<endl;
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