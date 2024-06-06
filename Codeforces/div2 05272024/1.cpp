#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,m;
    cin>>n>>m;

    int tempval = n-m;

    if(tempval<0)
    {
        cout<<"no"<<endl;
        return;
    }
    else
    {
        if(tempval%2==0)
        {
            cout<<"yes"<<endl;
            return;
        }
        else
        {
            cout<<"no"<<endl;
            return;
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