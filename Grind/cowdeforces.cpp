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

        vector<int> arr(n+1,0);

        for(int i=1; i<n+1; i++ )
        {
            cin>>arr[i];
        }

        vector<int>val1(n+1,0),val2(n+1,0);
        int maxval=-1,prevmaxval=-1;

        for(int i=1; i<n+1; i++)
        {
            val1[i] = prevmaxval;
            maxval = max(maxval, arr[i]);
            prevmaxval = maxval;
        }

        int newindx=n+1;


        for(int i=n; i>=1; i--)
        {
            val2[i] = newindx;
            if(arr[i]>arr[k])
            {
                newindx = i;
            }
        }
        
        int curr_max=-1,totalmax=-1;
        for(int i=1; i<n+1; i++)
        {
            curr_max=0;
            if(i>=k)
            {
                if(max(val1[i],arr[i])>arr[k]) curr_max=0;
                else
                {
                    if(i!=1) curr_max++;
                    curr_max += val2[i]-i-1;
                }

            }
            else
            {
                if(val1[i]>arr[k]) curr_max=0;
                else
                {
                    if(i!=1) curr_max++;
                    if (val2[i] < k)
                        curr_max += val2[i] - i - 1;
                    else
                    {
                        if(arr[i]>arr[k]) val2[i] = k;
                        curr_max += val2[i] - i - 1;
                    }
                } 
            }

           //  cout<<curr_max;

            totalmax = max(totalmax, curr_max);
        }
        // cout<<endl;

        // for(int i=1; i<n+1; i++) cout<<val1[i]<<" ";
        // cout<<endl;
        // for (int i = 1; i < n + 1; i++)
        //     cout << val2[i]<<" ";
        // cout<<endl;
        cout<<totalmax<<endl;



    }

    return 0;
}