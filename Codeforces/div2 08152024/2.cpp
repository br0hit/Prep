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
    int l,r;
    int L,R;

    cin>>l>>r>>L>>R;

    int finalans=-1;

    if(l>L)
    {
        int temp = l;
        l = L;
        L= temp;

        int temp1 = r;
        r = R;
        R = temp1;
    }

    if(l==L)
    {
        if(R<r)
        {
            finalans = R-L+1;
        }
        else if(R==r)
        {
            finalans = r-l;
        }
        else finalans = r-l+1;
    }
    else if(L<r)
    {
        if(R<r)
        {
            finalans = R-L+2;
        }
        else if(R==r)
        {
            finalans = r-L+1;
        }
        else finalans = r-L+2;
    }
    else if(L==r)
    {
        finalans = 2;
    }
    else finalans =1;

    cout<<finalans<<endl;
    return;
}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}