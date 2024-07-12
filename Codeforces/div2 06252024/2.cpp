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
int i;

int modval = 1e9 + 7;

void solve()
{
    ll x,y,k;
    cin>>x>>y>>k;

    ll rem;

    while(1)
    {
        // if(x<=y)
        // {

        // }

        rem = x%y;
        if(rem==0) rem=y;
        else rem= y-rem;

        //cout<<rem<<" "<<k<<endl;

        if(rem>k)
        {
            cout<<x+k<<endl;
            return;
        }
        else
        {
            k= k-rem;
            x=x+rem;
            while(x%y==0)
            {
                x= x/y;
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}