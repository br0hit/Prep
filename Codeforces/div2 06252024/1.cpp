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
    ll x1,y1,x2,y2;

    cin>>x1>>y1>>x2>>y2;

    if(x1==x2 && y1==y2)
    {
        cout<<"YES"<<endl;
        return;
    }

    if(x1==x2)
    {
        if(y1<x1 && y2>x1)
        {
            cout<<"NO"<<endl;
            return;
        }
        else
        {
            cout<<"YES"<<endl;
            return;
        }
    }

    if (y1 == y2)
    {
        if (x1 < y1 && x2 > y1)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            cout << "YES" << endl;
            return;
        }
    }

    // cout << "YES" << endl;
    // return;

    if(x2>y2)
    {
        if(x1>y1)
        {
            cout<<"YES"<<endl;
            return;
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    if (y2 > x2)
    {
        if (y1 > x1)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }

    return;
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