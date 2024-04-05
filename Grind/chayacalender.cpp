#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin>>n;

        vector<int> a(n,0);

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        int count=a[0];
        
        for(int i=1; i<n; i++)
        {   
            count++;

            if(count==a[i]) continue;
            else
            {
                if(a[i]>count) count = a[i];
                else
                {
                    
                    int temp_val = count/a[i] +1 ;

                    if (count % a[i] == 0) temp_val = count/a[i];
                    count = temp_val * a[i];
                    // while(1)
                    // {
                    //     temp_val++;
                    //     if(temp_val*a[i]>=count)
                    //     {
                    //         count = temp_val*a[i];
                    //         break;
                    //     }
                        
                    // }
                }
            }
        }

        cout<<count<<endl;
    }


    return 0;
}
