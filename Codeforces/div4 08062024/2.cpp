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
    int a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;

    if(a1<a2)
    {
        int tempval = a2;
        a2=a1;
        a1= tempval;
    }
    if (b1 < b2)
    {
        int tempval =b2;
        b2 =b1;
        b1 = tempval;
    }

    //cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<endl;

    int caseval=0;

    if(a1!=a2)
    {
        if(b1==b2)
        {
            if(b1>a2)
            {
                caseval=0;
            }
            else caseval=4;
        }
        else
        {
            if(b1>a1) caseval=0;
            else if(b1==a1)
            {
                if(b2<a2) caseval=2;
            }
            else if(b1<a1 && b1>a2)
            {
                if(b2<=a2) caseval=2;
            }
            else 
            {
                caseval=4;
            }
        }
    }
    else
    {
        if(b1==b2)
        {
            if(b1<a2) caseval=4;
            else caseval=0;
        }
        else
        {
            if(b1<=a1) caseval = 4;
            else caseval=0;
        }
    }

    cout<<caseval<<endl;
    return; 

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}