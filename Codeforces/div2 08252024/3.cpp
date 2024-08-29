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

    vector<int> a(26,0);
    int i;
    fr(i,0,n)
    {
        a[s[i]-'a']++;
    }

    string finalans="";

    while(1)
    {
        int tempval = 0;

        fr(i,0,26)
        {
            if(a[i]!=0)
            {
                finalans += (i+'a');
                a[i]--;
                //cout<<finalans<<endl;
                tempval=1;
            }
        }

        if(tempval==0) break;
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