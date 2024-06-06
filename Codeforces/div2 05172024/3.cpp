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
        cin >> n;

        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> newarr(n,0);
        for(int i=0; i<n; i++)
        {
            newarr[i] = n+1 - arr[i];
        }

        

        for(int i=1; i<n-1; i++)
        {
            // cout<<i<<" ";
            if(newarr[i]>newarr[i-1]&&newarr[i]>newarr[i+1])
            {
                // cout<<"Case 1";
                continue;
            }
            else if(newarr[i+1]<newarr[i-1])
            {
                // cout<<"case2";
                int temp = newarr[i-1];
                newarr[i-1] = newarr[i];
                newarr[i] = temp;
                i++;
            }
            else
            {
               //  cout<<"case3";
                int temp = newarr[i + 1];
                newarr[i + 1] = newarr[i];
                newarr[i] = temp;
                i++;
            }
            // cout<<endl;
        }

        for(int i=0; i<n; i++)
        {
            cout<<newarr[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}