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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n, 0);
    ll i;
    ll addval = 2;
    fr(i, 0, n)
    {
        ll temp;
        cin>>temp;

        temp+=addval;
        a[i]=temp;;
    }

    fr(i,0,n)cout<<a[i]<<" ";
    cout<<endl;

    ll l=0;
    ll sum = 0;
    ll count = 0;

    fr(i, 0, n)
    {
        sum += a[i];
        cout << i << " " << sum <<" "<< x + addval * (i - l + 1)<< endl;

        if (sum > x+addval*(i-l+1))
        {
            cout<<"Here"<<endl;
            cout<<i<<" "<<sum<<endl;
            while (sum > x + addval * (i - l + 1) && l <= i)
            {
                sum -= a[l];
                l++;
            }
            cout<<sum<<endl;
        }
        if (sum == x+addval*(i-l+1))
        {
            cout<<sum<<" "<<i<<" "<<l<<endl;
            count++;
        }
    }

    cout << count << endl;
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