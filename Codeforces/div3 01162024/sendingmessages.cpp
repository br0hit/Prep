#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,f,a,b;
        cin>>n>>f>>a>>b;

        vector<int> m(n,0);

        for(int i=0; i<n; i++)
        {
            cin>>m[i];
        }

        int curr_charge=f;
        int charge1,charge2;
        int charge_temp;
        int diff_moment;

        
        diff_moment = m[0];

        charge1 = diff_moment*a;
        charge2 = b;

        if(charge1>charge2)
        {
            charge_temp = charge2;
            curr_charge = curr_charge-charge_temp;
        }
        else
        {
            charge_temp = charge1;
            curr_charge = curr_charge-charge_temp;
            if(curr_charge<=0) cout<<"no"<<endl;
        }

        int i;

        for( i=1; i<n; i++)
        {
            diff_moment = m[i] - m[i-1];

            charge1 = diff_moment*b;
            charge2 = b;

            if(charge1>charge2)
            {
                charge_temp = charge2;
                curr_charge = curr_charge-charge_temp;
                if(curr_charge<0) 
                {
                    cout<<"no"<<endl;
                continue;
                }
            }
            else
            {
                charge_temp = charge1;
                curr_charge = curr_charge-charge_temp;
                if(curr_charge<=0) 
                {cout<<"no"<<endl;
                continue;}
            }

        }
    }
    //cout<<endl;

    return 0;
}
