#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {

        int n;
        cin>>n;

        vector<int> a(n,0);

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        int temp=0;

        for(int i=0; i<n-2; i++)
        {
            if(a[i]<0)
            {
                // cout<<"NO"<<endl;
                temp=-1;
                break;
            }

            if(a[i]==0) continue;

            a[i+1]= a[i+1]-2*a[i];
            a[i+2]= a[i+2]-a[i];

            // cout << i << a[i + 1] << a[i + 2] << endl;
        }

        if(temp==0)
        {
            if (a[n - 1] == 0 && a[n - 2] == 0)
            {
                temp = 0;
            }
            else
                temp = -1;
        }


        if(temp==0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;

    }

    return 0;
}
