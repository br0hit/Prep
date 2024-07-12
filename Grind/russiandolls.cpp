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
    int n;
    cin>>n;

    vector<int> dolls(n,0);
    int i;
    fr(i,0,n) cin>>dolls[i];

    sort(dolls.rbegin(), dolls.rend());

    int count=0;
    int j,k;

    fr(i,0,n)   
    {
        int pos = i+1;
        int tempval=0;
        fr(j,pos,n)
        {
            if(dolls[j]==dolls[i])
            {
                tempval++;
            }
        }
    }


}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       solve();
}