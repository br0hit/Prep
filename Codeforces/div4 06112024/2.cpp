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
    int n;
    cin>>n;

    int i;
    int maxsum=-1, index;
    fr(i,2,n+1)
    {
        int j;
        int sum=0;
        fr(j,1,n+1)
        {
            if(j*i>n) break;
            sum += j*i;
        }

        if(sum>maxsum)
        {
            maxsum = sum;
            index = i;
        }
    }


    cout<<index<<endl;
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