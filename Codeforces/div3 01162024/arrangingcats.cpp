#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n_boxes;
        cin>>n_boxes;

        string s;
        cin>>s;

        string f;
        cin>>f;

        int count1=0,count2=0;

        for(int i=0; i<n_boxes; i++)
        {
            if(s[i]=='1' && f[i]=='0') count1++;
            else if (s[i]=='0'&&f[i]=='1')
            {
                count2++;
            }   
        }

        if(count2>count1)
        {
            cout<<count2<<endl;
        }
        else
        {
            cout<<count1<<endl;
        }

    }

    return 0;
}
