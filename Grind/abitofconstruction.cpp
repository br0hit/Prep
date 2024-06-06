#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n,k;
        cin>>n>>k;

        int pow=1;
        int val,prev;

        vector<int> ans(n,0);

        if(n==1)
        {
            cout<<k<<endl;
            continue;
        }
    
        while(1)
        {
            prev = val;
            pow*=2;
            val = pow-1;

            if(k/val==0) break;
        }

        ans[0] = prev;
        ans[1] = k-prev;

        for(int i=0; i<n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }   

    return 0;
}