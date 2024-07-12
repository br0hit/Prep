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

int dfs(int node, vector<int> &visited, vector<vector<int>> &gr, vector<int> &parent, int start, int count)
{

    visited[node] = 1;
    count += 1;

    for (auto u : gr[node])
    {
        // cout<<u<<" "<<"Parent node "<<node<<endl;

        if (u != start && !visited[u])
        {
            parent[u] = node;
            int ans = dfs(u, visited, gr, parent, start, count);
            if (ans == 1)
                return 1;
            else
                continue;
        }
        else if (u == start)
        {
            if (count >= 3)
            {
                parent[start] = node;
                return 1;
            }
        }
    }

    return 0;
}

int bfs(int start, vector<int> &visited, vector<vector<int>> &gr, vector<int> &parent, vector<int> &distance)
{
    queue<int> qu;
    qu.push(start);
    visited[start] = 1;
    distance[start] = 0;

    while (!qu.empty())
    {
        int topnode = qu.front();
        qu.pop();

        cout << endl
             << endl
             << topnode << " " << endl
             << endl;

        for (auto u : gr[topnode])
        {
            if (u != start && !visited[u])
            {
                cout << "Entered " << u << " " << start << endl;
                visited[u] = 1;
                parent[u] = topnode;
                distance[u] = distance[topnode] + 1;
                cout << parent[u] << " " << u << " " << distance[u] << " " << endl;

                qu.push(u);
            }

            if (u == start)
            {
                cout << "Here " << topnode << " " << distance[topnode];
                if (distance[topnode] >= 2)
                {
                    parent[u] = topnode;
                    return 1;
                }
            }
        }
    }

    return 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> gr(n+1);
    int i;
    fr(i, 0, m)
    {
        int val1, val2;
        cin >> val1 >> val2;

        gr[val1].push_back(val2);
        gr[val2].push_back(val1);
    }

    int count;

    fr(i, 1, n + 1)
    {
        count = 0;
        // visited.clear();
        // visited.resize(n+1,0);
        // parent.clear();
        // parent.resize(n+1,0);
        // distance.clear();
        // distance.resize(n+1,0);
        vector<int> visited(n + 1, 0);
        vector<int> parent(n + 1, 0);
        vector<int> distance(n + 1, 0);

        // cout<<"New one";

        int ans = dfs(i, visited, gr, parent, i, count);
        // cout<<"three";
        if (ans == 1)
        {
            stack<int> ans;
            ans.push(i);
            int tempval = i;
            while (1)
            {
                int node = parent[tempval];
                ans.push(node);
                if (node == i)
                    break;
                tempval = node;
            }
            if (ans.size() >= 4)
            {
                cout << ans.size() << endl;
                while (!ans.empty())
                {
                    cout << ans.top() << " ";
                    ans.pop();
                }
                return;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
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