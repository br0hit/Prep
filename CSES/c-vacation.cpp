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

pair<int,int> typeval(int a, int b, int c)
{
    if(a>b && a>c) return {1,a};
    if(b>a && b>c) return {2,b};
    if(c>a && c>b) return {3,c};
    if(a==b && a>c) return {4,a};
    if(b==c && b>a) return {5,b};
    if(c==a && a>b) return {6,c};
    return {7,a};
}

void solve()
{
    int n;
    cin>>n;

    vi a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);

    int i;
    fr(i,1,n+1) cin>>a[i]>>b[i]>>c[i];

   vector<int> dp(n+1,0);
   vector<int> type(n+1,0);

   auto currtype = typeval(a[0],b[0],c[0]);
   if(n==1)
   {
        cout<<currtype.second;
        return;
   }

   dp[1] = currtype.second;
   type[1] = currtype.first;

   fr(i,2,n+1)
   {
        
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