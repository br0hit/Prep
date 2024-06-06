#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int l,r;
    cin>>l>>r;
    int count=1;

    while((r/(1<<count)))
    {
        // cout<<r/(1<<count)<<endl;
        // cout<<count<<endl;
        // cout<<(1<<count)<<endl;
        count++;
    }

    cout<<count-1<<endl;




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