#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        vector<int> x(4,0),y(4,0);

        cin>>x[0]>>y[0];
        cin>>x[1]>>y[1];
        cin>>x[2]>>y[2];
        cin>>x[3]>>y[3];

        for(int i=0; i<3; i++)
        {
            int min=1e9;
            int index;
            for(int j=i; j<4;j++)
            {
                if(x[j]<min)
                {
                    min = x[j];
                    index = j;
                }
            }

            int temp;

            temp = x[index];
            x[index] = x[i];
            x[i] = temp;

            
            temp = y[index];
            y[index] = y[i];
            y[i] = temp;
        }

        // for(int i=0; i<4; i++)
        //     {
        //         cout<<x[i]<<y[i]<<endl;
        //     }

        int area;

        area = y[1] - y[0];
        if(area<0) area = area*-1;

        cout<<area*area<<endl;
    }



    return 0;
}
