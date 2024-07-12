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
    ll x;
    cin>>x;

    if(x>=10 && x<=18)
    {
        cout<<"YES"<<endl;
        return;
    }

    if(x%10==9)
    {
        cout<<"NO"<<endl;
        return;
    }

    ll temp =x;
    ll last;
    ll second=0;

    while (temp)
    {
        last = temp%10;
        if(last==0 && second)
        {
            cout<<"NO"<<endl;
            return;
        }
        second++;
        temp = temp/10;
    }

    if(last==1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
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