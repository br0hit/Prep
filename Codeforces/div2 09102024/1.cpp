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
    int x,y,k;
    cin>>x>>y>>k;

    if(k%2==1)
    {
        cout<<x<<" "<<y<<endl;
        k--;
    }

    for(int i=1; i<k/2+1; i++)
    {
        cout<<x+i<<" "<<y+i<<endl;
        cout<<x-i<<" "<<y-i<<endl;
    }

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}