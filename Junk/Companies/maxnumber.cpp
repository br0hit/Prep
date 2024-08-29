#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define int long long
#define pb push_back
#define F first 
#define S second
#define mp make_pair
#define PI 3.1415926535897932384626
#define mod 1000000007
#define endl "\n"
#define ll long long
typedef pair<int, int> pii;
typedef pair<int, int> pl;
typedef vector<int> vi;
typedef vector<int> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

void printvec(vector<int> a){
    for(int i=0; i<(int)(a.size()); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
ll dp[200001][5][2];
ll rec(int i,string &s,int mx,bool c){
    int n=s.size();
    if(i==n) return 0;
    if(dp[i][mx][c]!=-1) return dp[i][mx][c];
    ll ans=-1e18;
    ll val[5]={1,10,100,1000,10000};
    if(c){
        if(mx>(s[i]-'A')) ans=-val[(s[i]-'A')];
        else ans=val[(s[i]-'A')];
        ans=ans+rec(i+1,s,max(mx,1ll*(s[i]-'A')),c);
        dp[i][mx][c]=ans;
        return dp[i][mx][c];
    }
    for(int j=0;j<5;j++){
        ll curr=0;
        if(mx>j) curr=-val[j];
        else curr=val[j];
        curr+=rec(i+1,s,max(mx,j),(s[i]-'A')!=j);
        ans=max(ans,curr);
    }
    dp[i][mx][c]=ans;
    return ans;
}
void solve(){
    string s;cin>>s;
    //A=0,B=1,C=2,D=3,E=4;
    int n=s.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++) dp[i][j][0]=-1,dp[i][j][1]=-1;
    }
    reverse(s.begin(),s.end());
    ll val=0;
    cout<<rec(0,s,0,0);
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t=1;
    //cin >> t;
    
    while (t--) {
        solve();
    }
    
 return 0;
}