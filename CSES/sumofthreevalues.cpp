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
    int i; fr(i,0,n) cin>>a[i];

    map<int,int> newmp;
    fr(i,0,n) newmp[a[i]]=i;

    if(n<=2 || (n==3 && a[0]+a[1]+a[2]!=x))
    {
        cout << "IMPOSSIBLE";
        return;
    }

    fr(i,0,n)
    {
        int newtarget = x-a[i];
        int index=i;

        // map<int,int> mp;

        for(int j=0; j<n; j++)
        {
            if(j!=index)
            {
                if(newmp.find(newtarget-a[j])!=newmp.end())
                {
                    cout<<index+1<<" "<<newmp[newtarget-a[j]]+1<<" "<<j+1;
                    return;
                }
                // else
                // {
                //     mp[a[j]] = j;
                // }
            }
        }
    }

    cout << "IMPOSSIBLE";
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