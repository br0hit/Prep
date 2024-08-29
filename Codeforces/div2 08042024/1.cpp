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

    string s;
    cin>>s;

    vector<int> ans(4,0);

    for(int i=0; i<4*n; i++)
    {
        if(s[i]!='?')
        ans[s[i]-'A']++;
    }

    int finalans=0;

    for(int i=0; i<4; i++)
    {
        if(ans[i]>=n) finalans+=n;
        else finalans +=ans[i];
    }

    cout<<finalans<<endl;
    return;

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}