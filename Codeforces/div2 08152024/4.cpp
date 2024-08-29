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

void setcolor(char color,int num,  set<int> &colb, set<int> &colg, set<int> &colr, set<int> &coly)
{
    if(color=='B')
    {
        colb.insert(num);
    }
    if(color=='R')
    {
        colr.insert(num);
    }
    if (color == 'G')
    {
        colg.insert(num);
    }
    if (color == 'Y')
    {
        coly.insert(num);
    }

    return;
}

int possible(int i, int j, vector<string> &portals)
{
    char p1 = portals[i][0];
    char p2 = portals[i][1];

    char q1 = portals[j][0];
    char q2 = portals[j][1];

    if(p1==q1 || p1==q2)
    {
        return abs(j-i);
    }

    if(p2==q1 || p2==q2)
    {
        return abs(j-i);
    }

    return 0;
}


void solve()
{
    int n,q;
    cin>>n>>q;

    vector<string> portals(n);
    int i;
    fr(i,0,n) cin>>portals[i];

    vector<pair<int,int>> queries(q);
    fr(i,0,q) cin>>queries[i].first>>queries[i].second;

    vector<vector<int>> dist(n,vector<int>(n,1e9));

    for(int i=0;i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int val = possible(i,j,portals);

            if(val!=0)
            {
                dist[i][j] = val;
            }
        }
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }



    fr(i,0,q)
    {
        int start = queries[i].first-1;
        int end = queries[i].second-1;

        priority_queue<pair<int,int>> pq;

        fr(j,0,n)
        {
            if(j!=start)
            if(possible(start,j,portals))
            {
                pq.insert({j,possible(start,j,portals)});
            }
        }

        while(!pq.empty())
        {
            auto u = pq.top();
            if(u.first ==end)
            {
                cout<<u.second<<endl;
            }
            else
            {
                
            }
        }

        int distanceval = dist[start][end];
        if(distanceval==1e9)
        {
            cout<<-1<<endl;
        }
        else cout<<distanceval<<endl;

    }

    return;

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}