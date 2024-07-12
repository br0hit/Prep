#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define endl '\n'
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second
int modval = 1e9 + 7;

void dfs(int s, int e, vector<vector<int>> &adj, vector<int> &count)
{
    // cout<<s<<" "<<e<<endl;
    count[s]=1;
    for(auto u: adj[s])
    {
        if(u!= e)
        {
            dfs(u, s, adj, count);
            count[s] += count[u];
            // cout << u << " count " << count[u] << " ";
        }

    }
    cout<<endl;
}


void solve()
{
    int n;
    cin>>n;

    vector<int> tree(n+1,0);
    vector<vector<int>> adj(n + 1);
    vector<int> count(n+1,0);

    int i;
    fr(i,2,n+1)
    {
        int t;
        cin>>t;
        adj[t].push_back(i);
        adj[i].push_back(t);
    }

    dfs(1,0, adj, count);

    fr(i,1,n+1)
    {
        cout<<count[i]-1<<" ";
    }
}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       solve();
}