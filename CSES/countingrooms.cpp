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

void dfs(int v, vector<int> &visited, vector<int> gr[])
{
    // cout<<"inside dfs "<<v<<endl;
    // for (auto u : gr[v])
    // {   cout<<u<<" ";} cout<<endl;

        visited[v] = 1;
        for (auto u : gr[v])
        {
            // cout << u << endl;
            if (!visited[u])
            {
                // cout << u << endl;
                dfs(u, visited, gr);
            }
        }
        // cout << "Outside dfs" << endl;
}


void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> adj(n + 2, vector<char>(m + 2, '\0'));
    vector<int> gr[n * m + 1];
    int i, j;
    fr(i, 1, n + 1)
    {
        fr(j, 1, m + 1)
        {
            cin >> adj[i][j];
        }
    }

    fr(i, 1, n + 1)
    {
        fr(j, 1, m + 1)
        {
            if (adj[i][j] == '.')
            {
                gr[m * (i - 1) + j].push_back(m * (i-1) + j);
                if (adj[i + 1][j] == '.')
                    gr[m * (i - 1) + j].push_back(m * (i) + j);
                if (adj[i][j + 1] == '.')
                    gr[m * (i - 1) + j].push_back(m * (i - 1) + j + 1);
                if (adj[i - 1][j] == '.')
                    gr[m * (i - 1) + j].push_back(m * (i - 2) + j);
                if (adj[i][j - 1] == '.')
                    gr[m * (i - 1) + j].push_back(m * (i - 1) + j - 1);
            }
        }
    }

    // fr(i, 1, n + 1)
    // {
    //     fr(j, 1, m + 1)
    //     {
    //         // cout<<m*(i-1)+j<<"   ";
    //         for (auto u : gr[m * (i - 1) + j])
    //             // cout << u << " ";
    //     }
    //     // cout << endl;
    // }

    // fr(i,1,n*m+1)
    // {
    //     // cout<<i<<endl;
    //     for (auto u : gr[i])
    //         // cout << u << " ";
    //     // cout<<endl;
    // }

    vector<int> visited(n * m + 1, 0);
    int count = 0;
    fr(i, 1, n * m + 1)
    {
        for (auto u : gr[i])
        {
            if (!visited[u])
            {
                // cout << u << endl;
                count++;
                dfs(u, visited, gr);    
            }
        }
    }

    cout << count << endl;
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