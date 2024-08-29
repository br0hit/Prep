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

    vector<int> x(n);
    int i;
    fr(i,0,n) cin>>x[i];
    int cond=1;

    if(n>=3)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(x[1]-x[0]>1)
    {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
    return;


}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}