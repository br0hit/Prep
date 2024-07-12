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
    int x,y;
    cin>>x>>y;

    int val=0;

    int i;
    // cout << (x & (1 << 0)) << endl;
    // cout << (y & (1 << 0)) << endl;

    fr(i,0,modval)
    {
        // cout<< (x&(1<<i))<<endl;
        // cout << (y & (1 << i)) << endl;

        if((x&(1<<i)) != (y&(1<<i)))
        {
            cout<<(1<<i)<<endl;
            return;
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t; while (t--)
    solve();
    return 0;
}