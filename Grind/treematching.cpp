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

int dfs(int node, int parent, vector<int> gr[], int val1, int val2, int count)
{
    
}


void solve()
{
    int n;
    cin>>n;

    vector<int> gr[n];

    int i;
    fr(i,0,n-1)
    {
        int val1,val2;
        cin>>val1>>val2;

        gr[val1].push_back(val2);
        gr[val2].push_back(val1);
    }

    int val1=0, val2=0;
    int turn=0;

    int ans =  dfs(1,0, gr, val1, val2, count);

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       solve();
}