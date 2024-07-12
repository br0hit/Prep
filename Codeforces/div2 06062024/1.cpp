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

void solve()
{
    int n;
    cin>>n;
    vi a(n,0);
    int i; fr(i,0,n) cin>>a[i];

    int first, last;
    int maxval= max(a[0],a[1]);
    int tempmax;

    fr(i,0,n-1)
    {
        if(a[i+1]>a[i])
        {
            tempmax = a[i+1];
        }
        else
        {
            tempmax = a[i];
        }
        maxval = min(tempmax, maxval);
    }

    cout<<--maxval<<endl;
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