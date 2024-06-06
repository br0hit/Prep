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
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0; i<n; i++) cin>>arr[i];

        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        vector<int> temp(n,0);

        int curr_val=arr[0];
        temp[0] = arr[0];

        for(int i=1; i<n; i++)
        {
            temp[i] = temp[i-1]|arr[i];
        }

        for(int i=0; i<n; i++) cout<<temp[i]<<" "; cout<<endl;
        
        int indx;
        for(int i=n-1; i>=0; i--)
        {
            if(temp[i] != temp[i-1])
            {
                indx = i;
                break;
            }
        }

        cout<<indx+1<<endl;

    }

    return 0;
}