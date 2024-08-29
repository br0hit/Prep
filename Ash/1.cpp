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
    vector<int> A = {4,2,1,-1,4,0,9,10};

    int n=A.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp1=A[j];
                int temp2=A[j+1];
                A[j]=temp2;
                A[j+1]=temp1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << A[i]<<" ";
    }

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}