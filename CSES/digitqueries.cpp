#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main()
{
    int q;
    cin>>q;

    long long int k;
   

    while(q--)
    {
        cin>>k;
        long long int tempsum, val10=1, currsum=0, prev_currsum=0,itr=1, num_vals, that_power,rem,that_power_num,ans;


        while(1)
        {
            prev_currsum = currsum;
            tempsum = val10*10-val10;
            currsum += tempsum*itr;
            val10 *=10;
            itr++;

            if((k/currsum)<=0) break;
        }

        itr--;
        k-=prev_currsum;
        num_vals = k/itr;

        that_power = pow(10,itr-1);
        that_power_num = that_power + num_vals-1;

        // cout<<" "<<itr<<" "<<k<<" "<<num_vals<<" "<<that_power<<" "<<that_power_num<<" "<<endl;

        if(k%itr==0) cout<<that_power_num%10<<endl;
        else
        {
            rem = k%itr;
            that_power_num++;
            while(rem!=0)
            {
                ans = that_power_num/that_power;
                that_power_num = that_power_num%that_power;
                that_power = that_power/10;
                rem--;
            }

            cout<<ans<<endl;
        }
    }
}