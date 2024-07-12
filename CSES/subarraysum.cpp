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
    int n,x;
    cin>>n>>x;
    vi a(n,0);
    int i;
    fr(i,0,n) cin>>a[i];

    int l=0,r=0,sum=0;
    int count=0;

    fr(i,0,n)
    {
        sum+=a[i];
        if(sum>x)
        {
            //cout<<i<<" "<<sum;
            while(sum>x && l<=i)
            {
                sum -= a[l];
                l++;
            }
            // cout<<sum<<endl;
        }
        if (sum == x)
        {
            count++;
        }
    }

    cout<<count<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin >> t; while (t--)
    solve();
    return 0;
}