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

    if(n%2==0)
    {
        cout<<-1<<endl;
        return;
    }
    int i;
    fr(i,0,n)
    {
        if(i%2==0 && i!=n-1)
        {
            cout<<(i+2)<<" ";
        }
        else if(i%2==0)
        {
            cout<<i+1<<endl;
            return;
        }
        else cout<<i<<" ";
    }


    return;



}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}