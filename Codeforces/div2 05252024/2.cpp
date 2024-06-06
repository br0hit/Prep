#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(),a.end());

    int num1,num2;
    num1 = a[0];
    int case1=0,case2=0;
    

    for(int i=1; i<n; i++)
    {
        if(case1==0)
        {
            if (a[i] % num1 != 0)
            {
                num2 = a[i];
                case1 =1;
            }
        }
        else
        {
            if(a[i]%num1!=0 && a[i]%num2!=0)
            {
                case2=1;
                break;
            }
        }
    }

    if(case2==1) cout<<"NO"<<endl;
    else cout<<"Yes"<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--)
    solve();
    return 0;
}