#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200000;
const int LOG = 18; // log2(200000) ~ 17.6

vector<int> adj[MAXN];
int magic[MAXN];
int depth[MAXN];
int parent[MAXN][LOG];

void dfs(int node, int par, int dep)
{
    parent[node][0] = par;
    depth[node] = dep;
    for (int i = 1; i < LOG; ++i)
    {
        if (parent[node][i - 1] == -1)
            break;
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }
    for (int neighbor : adj[node])
    {
        if (neighbor != par)
        {
            dfs(neighbor, node, dep + 1);
        }
    }
}

int getLCA(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; ++i)
    {
        if ((diff >> i) & 1)
            u = parent[u][i];
    }
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; --i)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int countOnPath(int u, int v, int w)
{
    int lca = getLCA(u, v);
    int count = 0;

    while (u != lca)
    {
        if (magic[u] <= w)
            count++;
        u = parent[u][0];
    }
    while (v != lca)
    {
        if (magic[v] <= w)
            count++;
        v = parent[v][0];
    }
    if (magic[lca] <= w)
        count++;

    return count;
}

void solve(int N, vector<int> &magic_values, vector<vector<int>> &edges, int Q, vector<vector<int>> &queries)
{
    for (int i = 0; i < N - 1; ++i)
    {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(&parent[0][0], &parent[0][0] + MAXN * LOG, -1);
    dfs(0, -1, 0);

    for (int i = 0; i < N; ++i)
    {
        magic[i] = magic_values[i];
    }

    for (const auto &query : queries)
    {
        int u = query[0] - 1;
        int v = query[1] - 1;
        int w = query[2];
        cout << countOnPath(u, v, w) << endl;
    }
}

int main()
{
    int N;
    cin >> N;

    vector<int> magic_values(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> magic_values[i];
    }

    vector<vector<int>> edges(N - 1, vector<int>(2));
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    int Q;
    cin >> Q;

    vector<vector<int>> queries(Q, vector<int>(3));
    for (int i = 0; i < Q; ++i)
    {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    solve(N, magic_values, edges, Q, queries);

    return 0;
}
