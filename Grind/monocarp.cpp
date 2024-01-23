#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<int> a(n,0),b(n,0);
        vector<int> sum(n,0),max(n,0);
        int max_val=-1e9;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(i>0)
            {
                sum[i] = sum[i-1] + a[i];
            }
            else sum[i] = a[i];
            
        }
        
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
            if(b[i]>=max_val)
            {
                max_val = b[i];
                max[i] = max_val;
            }
            else
            {
                max[i] = max_val;
            }
        }

        int max_work,temp_max;
        max_work = -1;

        for(int i=0; i<n && i<k; i++)
        {
        
            temp_max = sum[i] + max[i]*(k-i-1);
            // cout<<sum[i]<<" "<<max[i]<<" "<<temp_max<<endl;
            if(temp_max>max_work) max_work = temp_max;
        }

        cout<<max_work<<endl;

    }

    return 0;
}
