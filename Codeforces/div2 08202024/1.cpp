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

    vector<int> a(n,0);
    int i;
    fr(i,0,n) cin>>a[i];

    if(n==1)
    {
        cout<<0<<endl;
        return;
    }

    vector<int> freq(101,0);

    fr(i,0,n)
    {
        freq[a[i]]++;
    }

    int maxcount=0;

    fr(i,1,101)
    {
        if(freq[i]>maxcount)
        {
            maxcount = freq[i];
        }
    }

    cout<<n-maxcount<<endl;

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}