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
    int n;
    cin>>n;

    vector<int> r(n,0);

    vector<int> ans(n,0);

    int i;
    fr(i,0,n) cin>>r[i];
    i=0;

    for (auto u = r.rbegin(); u != r.rend(); u++)
    {
        ans[i] = *u;
        i++;
    }

    if(n%2==0)
    {
        for(auto u: ans)
        {
            cout<<u<<" ";
        }
    }
    else
    {
        int temp = ans[n/2];
        ans[n/2] = ans[n/2 +1];
        ans[n/2+1] = temp;

        for (auto u : ans)
        {
            cout << u << " ";
        }
    }
    cout<<endl;

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}