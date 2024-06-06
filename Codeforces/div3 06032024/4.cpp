#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n,0);
    for(int i=0; i<n; i++) cin>>a[i];

    if(n==3)
    {
        cout<<"YES"<<endl; return;
    }

    int ans,chance;
    int pos;

    int gcd1 = gcd(a[0],a[1]);
    if(gcd1==1)
    {
        for(int i=2; i<n; i++)
        {
            gcd1 = gcd(a[i],a[i-1]);
            if(gcd1!=1)
            {
                pos=i;
                break;
            } 
        }
    }
    if(pos>=n-2)
    {
        cout<<"YES"<<endl;
    }
    ans=0;
    chance=0;
    for (int i = pos; i < n ; i++)
    {
        if (a[i] % gcd1 == 0)
        {
            continue;
        }
        else
        {
            chance++;
            if(chance>1) 
            {
                ans = 1;
                break;
            }
        }
    }

    if(ans==0)
    {
        cout<<"YES1"<<endl;
        return;
    }

    int gcd2 = gcd(a[1],a[2]);
    if (gcd2 == 1)
    {
        for (int i = 3; i < n; i++)
        {
            gcd2 = gcd(a[i], a[i - 1]);
            if (gcd2 != 1)
            {
                pos = i;
                break;
            }
        }
    }
    if (pos >= n - 2)
    {
        cout << "YES" << endl;
    }
    ans=0;
    for (int i = pos; i < n; i++)
    {

        if (a[i] % gcd2 == 0)
        {
            continue;
        }
        else
        {
            ans = 1;
            break;
        }
    }

    if (ans == 0)
    {
        cout << "YES2" << endl;
        return;
    }

    int gcd3 = gcd(a[0],a[2]);
    if (gcd3 == 1)
    {
        for (int i = 3; i < n; i++)
        {
            gcd3 = gcd(a[i], a[i - 1]);
            if (gcd3 != 1)
            {
                pos = i;
                break;
            }
        }
    }
    if (pos >= n - 2)
    {
        cout << "YES" << endl;
    }
    ans=0;

    for(int i=pos; i<n; i++)
    {
        if(a[i]%gcd3==0)
        {
            continue;
        }
        else
        {
            ans=1;
            break;
        }
    }

    if (ans == 0)
    {
        cout << pos<<gcd3<<"YES3" << endl;
        return;
    }

    cout<<"NO"<<endl;
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