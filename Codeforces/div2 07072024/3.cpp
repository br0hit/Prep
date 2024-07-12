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
    ll n;
    cin>>n;

    vector<ll> a(n,0),b(n,0),c(n,0);
    vector<ll> apref(n, 0), bpref(n, 0), cpref(n, 0);

    ll i;
    fr(i,0,n) cin>>a[i];
    fr(i, 0, n) cin >> b[i];
    fr(i, 0, n) cin >> c[i];

    apref[0]= a[0];
    bpref[0] = b[0];
    cpref[0] = c[0];

    fr(i,1,n)
    {
        apref[i] = apref[i-1]+a[i];
        bpref[i] = bpref[i - 1] + b[i];
        cpref[i] = cpref[i - 1] + c[i];
    }



    ll tot=0;
    fr(i,0,n) tot+=a[i];

    ll minval = tot/3;
    if(tot%3!=0) minval++;

    ll currvala=0,currvalb=0,currvalc=0;

    ll amax,amin,bmax,bmin,cmax,cmin;

    ll a1,a2,b1,b2,c1,c2;

    ll j,k;

    amax=0;
    amin =0;
    bmax=0;
    bmin=0;
    cmax=0;
    cmin=0;

    fr(i,0,n)
    {
        currvala+=a[i];
        currvalb+=b[i];
        currvalc+=c[i];

        if(currvala>=minval && !amax)
        {
            amax=1;
            a1 = 0;
            a2 = i;

            currvalb =0;
            currvalc=0;

            bmin=0;
            cmin=0;

            fr(j,i+1,n)
            {
                currvalb+=b[j];
                currvalc+=c[j];

                if(currvalb>=minval && !bmin)
                {
                    bmin=1;
                    b1 = i+1;
                    b2 = j;

                    c1 = j + 1;
                    c2 = n - 1;

                    if(cpref[n-1]-cpref[j]>=minval)
                    {
                        cout << a1 + 1 << " " << a2 + 1 << " " << b1 + 1 << " " << b2 + 1 << " " << c1 + 1 << " " << c2 + 1 << endl;
                        return;
                    }
                }
                if(currvalc>=minval && !cmin)
                {
                    cmin=1;
                    c1 = i+1;
                    c2 = j;
                    b1 = j + 1;
                    b2 = n - 1;
                    if (bpref[n - 1] - bpref[j]>=minval)
                    {
                        cout << a1 + 1 << " " << a2 + 1 << " " << b1 + 1 << " " << b2 + 1 << " " << c1 + 1 << " " << c2 + 1 << endl;
                        return;
                    }
                }
            }
        }

        if (currvalb >= minval && !bmax)
        {
            bmax=1;
            amin=0;
            cmin=0;
            b1 = 0;
            b2 = i;

            currvala = 0;
            currvalc = 0;

            fr(j, i + 1, n)
            {
                currvala += a[j];
                currvalc += c[j];

                if (currvala >= minval && !amin)
                {
                    amin=1;
                    a1 = i + 1;
                    a2 = j;

                    c1 = j + 1;
                    c2 = n - 1;

                    if (cpref[n - 1] - cpref[j] >= minval)
                    {
                        cout << a1 + 1 << " " << a2 + 1 << " " << b1 + 1 << " " << b2 + 1 << " " << c1 + 1 << " " << c2 + 1 << endl;
                        return;
                    }
                }
                if (currvalc >= minval && !cmin)
                {
                    cmin=1;
                    c1 = i + 1;
                    c2 = j;
                    a1 = j + 1;
                    a2 = n - 1;
                    if (apref[n - 1] - apref[j] >= minval)
                    {
                        cout << a1 + 1 << " " << a2 + 1 << " " << b1 + 1 << " " << b2 + 1 << " " << c1 + 1 << " " << c2 + 1 << endl;
                        return;
                    }
                }
            }
        }

        if (currvalc >= minval && !cmax)
        {
            cmax=1;
            amin=0;
            bmin=0;
            c1 = 0;
            c2 = i;

            currvala = 0;
            currvalb = 0;

            fr(j, i + 1, n)
            {
                currvala += a[j];
                currvalb += b[j];

                if (currvala >= minval && !amin)
                {
                    amin=1;
                    a1 = i + 1;
                    a2 = j;

                    b1 = j + 1;
                    b2 = n - 1;

                    if (bpref[n - 1] - bpref[j] >= minval)
                    {
                        cout << a1 + 1 << " " << a2 + 1 << " " << b1 + 1 << " " << b2 + 1 << " " << c1 + 1 << " " << c2 + 1 << endl;
                        return;
                    }
                }
                
                if (currvalb >= minval && !bmin)
                {
                    bmin=1;
                    b1 = i + 1;
                    b2 = j;
                    a1 = j + 1;
                    a2 = n - 1;
                    if (apref[n - 1] - apref[j] >= minval)
                    {
                        cout << a1 + 1 << " " << a2 + 1 << " " << b1 + 1 << " " << b2 + 1 << " " << c1 + 1 << " " << c2 + 1 << endl;
                        return;
                    }
                }
            }
        }
    }

    cout<<-1<<endl;
    return;

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}