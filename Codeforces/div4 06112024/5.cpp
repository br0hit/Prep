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
    ll x,y,z,kval;
    cin>>x>>y>>z>>kval;

    vector<ll> nerd={x,y,z};
    sort(nerd.begin(),nerd.end());

    z = nerd[2];
    y = nerd[1];
    x = nerd[0];

    ll val=0;   

    for(ll i= x; i>=1; i--)
    {
        // cout << "first loop" << endl;
        if(kval%i==0)
        {
            // cout<<"here also"<<endl;
            for(ll j= min((kval/i),y); j>=1; j--)
            {
                // cout<<"second loop"<<endl;
                if((kval%(i*j))==0)
                {
                    // cout<<"here"<<endl;
                    ll k = kval/(i*j);
                    // cout<<i<<" "<<j<<" "<<k<<" "<<endl;
                    if(k>=1 && k<= z)
                    {
                        ll newval = (z-k+1)*(y-j+1)*(x-i+1);
                        if(newval>val)
                        {
                            val = newval;
                        }
                    }
                }
            }
        }
    }

    cout<<val<<endl;


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

/*
    // cout<<x<<y<<z<<endl;

    ll x1,y1,z1;

    ll tempk =k;

    ll i;

    fr1(i,z)
    {
        if(k==1)
        {
            z1=1;
            break;
        }
        if(k%i==0)
        {
            z1=i;
            break;
        }
    }

    tempk = tempk/z1;

    fr1(i, y)
    {
        if ((tempk) == 1)
        {
            y1 = 1;
            break;
        }
        if ((tempk) % i == 0)
        {
            y1=i;
            break;
        }
    }

    tempk = tempk/y1;

    fr1(i, x )
    {
        if ((tempk) == 1)
        {
            x1 = 1;
            break;
        }
        if ((tempk) % i == 0)
        {
            x1 = i;
            break;
        }
    }

    if(z1*y1*x1!=k)
    {
        cout<<-1<<endl;
        return;
    }

    cout<<(z-z1+1)*(y-y1+1)*(x-x1+1)<<endl;
*/