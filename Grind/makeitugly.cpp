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

        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        int val = arr[0];
        int count=0, countmin=1e9;

        for(int i=0; i<n; i++)
        {
            if(arr[i]==val) count++;
            if(arr[i]!=val)
            {
                countmin = min(countmin, count);
                count=0;
            }
        }

        countmin = min(countmin, count);

        if(count==n) 
        { 
            cout<<-1<<endl;
            continue;
        }
        else 
        {
            cout<<countmin<<endl;
        }
    }

    return 0;
}