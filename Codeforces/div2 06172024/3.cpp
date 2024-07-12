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
    ll n,k;
    cin>>n>>k;

    if(k%2==1)
    {
        cout<<"NO"<<endl;
        return;
    }

    ll maxsum;
    if(n%2==0)
    {
        maxsum = 2*pow(2,n/2);
    }
    else
    {
        ll k=n/2;
        maxsum = 4*(k*(k+1))/2;
    }

    if(k>maxsum)
    {
        cout<<"NO"<<endl;
        return;
    }

    ll rem=k;
    ll j;

    vector<ll> arr(n+1,0);
    fr(i,1,n+1) arr[i]=i;

    fr(i,1,(n/2)+1)
    {
        int tempsum = (n - (2*(i-1)+1))*2;
        // cout<<tempsum<<endl;
        if(rem>=tempsum)
        {
            rem = rem-tempsum;
            arr[i] = n-i+1;
            arr[n-i+1] = i; 
        }
        else
        {
            ll val= rem/2;
            arr[i] = i+val;
            arr[i+val]=i;
            break;
        }
    }
    // if(rem>0)
    // {
    //     cout<<"NO"<<endl;
    //     return;
    // }
    cout<<"YES"<<endl;
    fr(i,1,n+1)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

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