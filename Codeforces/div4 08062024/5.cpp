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
    ll l,r;
    cin>>l>>r;

    ll pow = 3;
    ll count=1;

    ll totalcount=0;

    while(l/pow)
    {
        pow = pow*3;
        count++;
    }

    totalcount += count*2;
    ll prevpow = pow;
    ll prevcount = count;

   //  cout<<pow<<" "<<count<<endl;

    if(r<pow)
    {
        totalcount += (r-l)*count;
        cout<<totalcount<<endl;
        return;
    }

    while(1)
    {
        if(r>=pow)
        {
            totalcount += (pow-l-1)*count;
            prevpow = pow;
            l = prevpow-1;
            pow = pow*3;
            count++;
        }
        else
        {
            totalcount += (r-prevpow+1)*count;
            break;
        }
    }

    cout<<totalcount<<endl;


}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}