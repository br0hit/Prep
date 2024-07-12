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

void solve()
{
    ll n, m,q;
    cin >> n >> m>>q;

    vector<pair<ll, ll>> gr[n + 1];
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, 1e18));

    ll i;
    fr(i, 0, m)
    {
        ll val1, val2, val3;
        cin >> val1 >> val2 >> val3;

        if(dist[val1][val2]!=1e18)
        {
            if(val3>dist[val1][val2])
            {
                continue;
            }
        }

        dist[val1][val2] = val3;
        dist[val2][val1] = val3;
    }

    ll j, k;

    fr(i,1,n+1)
    {
        fr(j,1,n+1) 
        {
            if(i==j) dist[i][j]=0;
        }
    } 

    fr(k,1,n+1)
    {
        fr(i,1,n+1)
        {
            fr(j,1,n+1)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    fr(i,0,q)
    {
        ll temp1,temp2;
        cin>>temp1>>temp2;

        if(dist[temp1][temp2]==1e18) dist[temp1][temp2]=-1;

        cout<<dist[temp1][temp2]<<endl;
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