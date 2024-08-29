#include<bits/stdc++.h>
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
    ll n,m;
    cin>>n>>m;

    vector<set<ll>> seq(n);
    vector<ll> sizevals(n);

    ll i;
    ll j;
    fr(i,0,n)
    {
        ll len;
        cin>>len;

        sizevals[i] = len;

        ll tempval;

        fr(j,0,len)
        {
            cin>>tempval;
            seq[i].insert(tempval);
        }
    }

    ll permaxval = -1;

    for(ll i=0; i<n; i++)
    {
        // seq[i].insert(0);
        ll missval = 0;
        ll cond=0;
        ll maxval = 0;

        for(auto it = seq[i].begin(); it!=seq[i].end(); it++)
        {
            if(*it==missval)
            {
                missval++;
            }
            else
            {
                cond=1;

                auto it1 = it;
                auto it2 = it;
                it2++;

                if(*it-missval==1)
                {
                    while(it2!=seq[i].end() && *it2-*it1==1)
                    {
                        it2++;
                        it1++;
                    }
                    maxval = *it1+1;
                }
                else maxval = missval+1;

                break;
            }
        }

        if(cond==0)
        {
            maxval = ++missval;
        }

        permaxval = max(maxval, permaxval);
    }

    ll finalans=0;

    if(m>permaxval)
    {
        finalans = ((m*(m+1))/2) + (permaxval*(permaxval+1))/2;
    }
    else
    {
        finalans = permaxval *(m+1);
    }

    cout<<finalans<<endl;





}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}