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

char getpath(int i, int j, int n)
{
    int l1 = (i/n)+1;
    int r1 = i-l1;

    int l2 = (j / n) + 1;
    int r2 = i - l2;

    if(l1==l2 && r1>r2)
    {
        return 'L';
    }
    if (l1 == l2 && r1 < r2)
    {
        return 'R';
    }
    if (l1 > l2 && r1 == r2)
    {
        return 'U';
    }
    return 'D';
}

void dfs(int v, vector<int> &visited, vector<int> gr[], vector<char> &path, int end, int n)
{
    visited[v]=1;
    if(v==end) return;
    for(auto u: gr[v])
    {
        if(!visited[u])
        {
            dfs(u,visited,gr,path,end, n);
        }
        path.push_back(getpath(v,u,n));
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<char>> adj(n+2,vector<char>(m+2,'\0'));
    int i,j;
    fr(i,1,n+1)
    {
        fr(j,1,m+1)
        {
            cin>>adj[i][j];
        }
    }

    vector<int> gr[n*m+1];

    int start,end;

    fr(i,1,n+1)
    {
        fr(j,1,m+1)
        {

            if(adj[i][j]=='A')
            {
                start = m * (i - 1) + j;
            }
            if (adj[i][j] == 'B')
            {
                end = m * (i - 1) + j;
            }

            if(adj[i][j]=='.'|| adj[i][j]=='A' || adj[i][j]=='B')
            {
                gr[m*(i-1)+j].push_back(m*(i-1)+j);

                if (adj[i+1][j] == '.' || adj[i+1][j] == 'A' || adj[i+1][j] == 'B')
                {
                    gr[m * (i - 1) + j].push_back(m * (i) + j);
                }
                if (adj[i ][j+1] == '.' || adj[i ][j+1] == 'A' || adj[i ][j+1] == 'B')
                {
                    gr[m * (i - 1) + j].push_back(m * (i-1) + j+1);
                }
                if (adj[i-1][j] == '.' || adj[i-1][j] == 'A' || adj[i-1][j] == 'B')
                {
                    gr[m * (i - 1) + j].push_back(m * (i-2) + j);
                }
                if (adj[i][j-1] == '.' || adj[i][j-1] == 'A' || adj[i][j-1] == 'B')
                {
                    gr[m * (i - 1) + j].push_back(m *(i-1) + j-1);
                }
            }
        }
    }

    // fr(i,1,n*m+1)
    // {
    //     cout<<i<<endl;
    //     for(auto u: gr[i])
    //     {
    //         cout<<u<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> visited(n*m+1,0);
    vector<char> path;

    cout<<start<<endl; 
    dfs(start, visited, gr, path, end, n);

    if(visited[end]==0)
    {
        cout<<"NO";
        return;
    }
    else
    {
        cout<<"YES"<<endl;
    }

    for(int i=0; i<path.size(); i++)
    {
        cout<<path[i];
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