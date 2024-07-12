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
    string a,b;
    cin>>a>>b;

    int i,j;

    int substrlen = a.length();

    map<char,int> mp;
    fr(i,0,substrlen)
    {
        mp[a[i]]++;
    }


    int subseq = b.length();
    int lencommon=0;

    int curr=0;
    int maxlencommon=-1;
    int k;

    fr(i,0,subseq)
    {
        curr=0;
        lencommon=0;
        fr(k,i,subseq)
        {
            fr(j,curr, substrlen)
            {
                if(a[j]==b[k])
                {
                    lencommon++;
                    curr=j+1;
                    break;
                }
            }
        }
        
        maxlencommon = max(lencommon, maxlencommon);
    }


    int ans = substrlen + subseq - maxlencommon;
    cout<<ans<<endl;

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}