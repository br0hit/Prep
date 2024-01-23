#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {   
        long long int n,p,l,t;
        cin>>n>>p>>l>>t;

        // long long int no_tasks = (n-1)/7 +1;
        long long int no_tasks = (n+6)/7;

        bool extra = no_tasks%2;
        long long int bigtaskdays = no_tasks/2;
        long long int temp,temp_rem;
        temp = p/(l+2*t);
        temp_rem = p%(1+2*t);

        // cout<<no_tasks<<" "<<extra<<" "<<bigtaskdays<<endl;

        //case 1
        if(bigtaskdays>0)
        {
            if(bigtaskdays>temp)
            {
                if(temp_rem==0)
                {
                cout<<n-temp<<endl;
                continue;
                }
                else
                {
                    cout<<n-temp-1<<endl;
                    continue;
                }
            }

            if(bigtaskdays==temp)
            {
                if(temp_rem==0)
                {
                    cout<<n-temp<<endl;
                    continue;
                }
            }

            p = p - bigtaskdays*(l+2*t);
 
        }           

        if(extra)
        {
            p-=(l+t);
            bigtaskdays++;
            if(p<=0) cout<<n-bigtaskdays<<endl;
            // cout<<"endedxtra"<<endl;
            continue;
        }

        long long int temp1 = p/l;
        if(p%l==0) cout<<n-bigtaskdays-temp1<<endl;
        else cout<<n-1-bigtaskdays-temp1<<endl;
    }

    return 0;
}
