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


void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> a(n,vector<int>(m,0)), b(n,vector<int>(n,0));

    int i,j;
    int temp;
    fr(i,0,n)
    {
        fr(j,0,m)
        {
            cin>>temp;

            // int val = temp - '0';
            a[i][j] = temp;
        }
    }
    fr(i, 0, n)
    {
        fr(j, 0, m)
        {
            cin >> temp;

            // int temp = temp - '0';
            b[i][j] = temp;
        }
    }
    cout<<"here"<<endl;
}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}