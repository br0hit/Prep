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

int findh(int node, int parent, vector<int> gr[], vector<int> &height, vector<int> &maxheights)
{
    cout<<node<<" "<<parent<<endl;
    int maxh=0;
    vector<int> temps;
    for(auto u: gr[node])
    {
        if(u==parent) continue;

        if(height[u]!=-1)
        {
            maxh = max(maxh, height[u]+1);
            temps.push_back(height[u]);
        }
        else
        {
            int val = findh(u, node, gr, height, maxheights);
            maxh = max(maxh, val + 1);
            temps.push_back(val);
        }
    }

    sort(temps.rbegin(),temps.rend());

    if(temps.size()==1)
    {
        maxheights[node] = temps[0]+1;
    }
    else maxheights[node] = temps[0] + temps[1] + 2;

    return height[node]=maxh;
}


void solve()
{
    cout << "Here" << endl;

    int n;
    cin>>n;
    cout << "Here" << endl;

    vector<int> gr[n+1];
    cout << "Here" << endl;

    int i;
    fr(i,0,n-1)
    {
        int t1,t2;
        cin>>t1>>t2;

        gr[t1].push_back(t2);
        gr[t2].push_back(t1);
    }

    cout << "Here" << endl;

    vector<int> height(n+1,-1);
    vector<int> maxh(n+1,0);

    cout<<"Here"<<endl;

    int tempstore = findh(1,0,gr,height, maxh);

    sort(maxh.rbegin(), maxh.rend());
    cout<<maxh[0]<<endl;
}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       solve();
}