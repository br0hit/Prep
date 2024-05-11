#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool customcompare(const int&a, const int&b) 
{
    if((a^b)<4)
    {
        return a<b;
    }
    return false;
}

int main()  
{
    int t;

    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> a(n,0);
        for(int i=0; i<n; i++) cin>>a[i];

        // for(int i=0; i<n-1; i++)
        // {
        //     for(int j=i+1; j<n; j++)
        //     {
        //         // cout<<i<<j<<(a[i]^a[j])<<endl;
        //         if((a[i]^a[j])<4)
        //         {
        //             if(a[i]>a[j])
        //             {
        //                 int temp = a[i];
        //                 a[i] = a[j];
        //                 a[j] = temp;
        //             }

        //         }
        //     }
        // }

        sort(a.begin(), a.end(), customcompare);

        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
    }

    return 0;
}