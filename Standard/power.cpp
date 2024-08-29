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

ll power(ll a, ll b)
{
    if(b==0) return 1;
    ll result = a;
    b--;

    while(b>1)
    {
        if(b%2==1) result = (result*a)%modval;
        b = b/2;
        result = (result * result)%modval;

        cout<<b<<" "<<result<<endl;
    }

    return result;
}

ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll result = a;
    b--;

    while (b > 1)
    {
        if (b % 2 == 1)
            result = (result * a) % modval;
        b = b / 2;
        result = (result * result) % modval;

        cout << b << " " << result << endl;
    }

    return result;
}

void solve()
{
        cout<<power(2,1)<<endl;
}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       solve();
}