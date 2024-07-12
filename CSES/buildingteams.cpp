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

int dfs(int node, vector<int> &visited, vector<int> gr[], int count)
{
    visited[node] = count;
    for(auto u: gr[node])
    {
        if(visited[u]==0)
        {
            int ans =  dfs(u,visited, gr, 3-count);
            if(ans==1) continue;
            else return 0;
        }
        else
        {
            if(visited[u]==3-count) continue;
            else return 0;
        }
    }

    return 1;
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
    int count=1;

    int answer;

    fr(i,1,n+1)
    {
        if(!visited[i])
        {
            answer = dfs(i,visited,gr, count);
            if(answer==1) continue;
            else 
            {
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }

    fr(i,1,n+1) cout<<visited[i]<<" ";



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