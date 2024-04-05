#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<long long> a(n,0);

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        long long temp,temp2,max,arr_sum;
        long long divide= 1e9+7;
        long long quot;

        long long temp3;

        max = temp = arr_sum= a[0];

        for(int i=1;i<n;i++)
        {
            arr_sum+=a[i];
            temp2 = a[i];
            if(temp>0)
            {
                temp+=temp2;
            }
            else temp=temp2;

            if(temp>max) max=temp;
        }

        if(max<0)
        {
            temp=arr_sum;

            // if (temp < 0)
            // {
            //     quot = 1;
            //     // cout<<divide;
            //     // cout<<-1*arr_sum%(-1*divide)<<endl;
            //     while (1)
            //     {
            //         if (arr_sum + quot * divide > 0)
            //             break;
            //         quot++;
            //     }

            //     cout << arr_sum + quot * divide << endl;
            //     break;
            // }
            // else
            // {
            //     cout << temp % divide << endl;
            //     break;
            // }
        }
        else
        {
            // cout<<arr_sum<<max<<"Here"<<endl;
            temp3=max;
            for(int i=0;i<k;i++)
            {
                temp3*=2;
                temp3 = temp3%divide;
                // cout << temp3<<endl;
            }
            // cout<<temp3;
            temp = (temp3 + (arr_sum-max));
            // cout<<temp<<endl;
        }

        if(temp<0)
        {
            quot = 1;
            // cout<<divide;
            // cout<<-1*arr_sum%(-1*divide)<<endl;
            while (1)
            {
                if (arr_sum + quot * divide > 0)
                    break;
                quot++;
            }

            cout << arr_sum + quot * divide << endl;
        }
        else
        {
            cout<<temp%divide<<endl;
        }


    }

}