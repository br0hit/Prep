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

int solve(int a1,int b1,int a2,int b2)
{
    if(a1>b1 && a2>b2)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void solve()
{
    int a1,a2,b1,b2;
    cin >>a1>>a2>>b1>>b2;
    int ans=0;
    ans=ans+solve(a1,b1,a2,b2);
    ans=ans+solve(a1,b2,a2,b1);
    ans=ans+solve(a2,b1,a1,b2);
    ans=ans+solve(a2,b2,a1,b1);
    cout << ans<<endl;
}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}
