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

void makequery(int a, int b, int n, int &edgecount, vector<vector<int>> &graph, vector<pair<int,int>> &ans)
{
    if(graph[a][b]!=0) return;

    cout<<"? "<<a<<" "<<b<<endl;
    cout.flush();
    int tempval;
    cin>>tempval;

    if(tempval==a || tempval==b)
    {
        graph[a][b] = 1;
        graph[b][a] = 1;
        ans.push_back({a,b});
        edgecount++;

        if (edgecount == n - 1)
        {
            cout << "! ";
            cout.flush();
            for (int i = 0; i < n-1 ; i++)
            {
                cout<<ans[i].F<<" "<<ans[i].S<<" ";
                cout.flush();
            }
            cout << endl;
            cout.flush();

            return;
        }
            
        
        return;
    }
    else
    {
        if(graph[a][tempval]==0) makequery(a,tempval,n,edgecount,graph,ans);
        if(graph[b][tempval]==0) makequery(b,tempval,n,edgecount,graph,ans);
        return;
    }
}


void solve()
{
    int n;
    cin>>n;

    int edgecount=0;
    vector<vector<int>> graph(n+1, vector<int>(n+1,0));
    vector<pair<int,int>> ans;

    for(int i=1; i<n+1; i++)
    {
        for(int j=i+1; j<n+1; j++)
        {
            if(graph[i][j]==0) makequery(i,j,n,edgecount,graph,ans);
            if(edgecount==n-1) return;
        }
    }
}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}