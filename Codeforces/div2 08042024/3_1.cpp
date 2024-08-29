#include <bits/stdc++.h>
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
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n, 0);
    ll i;
    fr(i, 0, n) cin >> a[i];

    if (n == 1)
    {
        cout << a[0] << endl;
        return;
    }

    sort(a.begin(), a.end());

    unordered_map<int,int> mods;

    vector<int> modsvec(2*k,0);

    for(int i=0; i<n-1; i++)
    {
        mods[a[i]%(2*k)]++;

        modsvec[a[i] % (2 * k)]++;
    }

    ll curr_k = 0;

    ll maxval = a[n - 1];
    ll maxminus1 = a[n - 2];

    for (int j = 0; j < k; j++)
    {
        ll tempval = maxval + j;
       // cout<<tempval<<endl;
        ll modtempval = tempval%(2*k);

        int cond=1;

        for(int u=1; u<=k; u++)
        {
            
            if(mods[(modtempval+u)%(2*k)])
            {   
                cond=0;
                j += u-1;
                break;
            }
        }

        if(cond==1)
        {
            cout<<tempval<<endl;
            return;
        }
    }


    // for(int i=startval; i<startval+k; i++)
    // {
    //     int cond=1;
    //     for(int u=1; u<=k; u++)
    //     {
    //         if(modsvec[(startval+u)%(2*k)])
    //         {
    //             i = startval+u-1;
    //             cond=0;
    //             break;
    //         }
    //     }

    //     if(cond==1)
    //     {
    //         cout<<i<<endl;
    //         return;
    //     }
    // }
    // ll startval = maxval % (2 * k);
    // ll newstart = startval;

    // ll count=0;
    // for(ll j=1; j<=k; j++)
    // {
    //     ll index = (startval+j)%(2*k);
    //     if(mods[index])
    //     {
    //         count=0;
    //         newstart = startval+j;
    //         j--;
    //     }
    //     else count++;

    //     if(count==k)
    //     {
    //         cout<<maxval+j-1<<endl;
    //         return;
    //     }
    // }
    cout << -1 << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}