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
int modval = 1e9;

vector<int> hashval(modval,0);
int countval = 0;


void solve()
{
    int n;
    cin>>n;

    int i;
    fr(i,0,n)
    {
        int temp;
        cin>>temp;

        if(hashval[temp]>0)
        {
            continue;
        }
        else
        {
            hashval[temp]++;
            countval++;
        }
    }

    cout<<countval<<endl;

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       solve();
}