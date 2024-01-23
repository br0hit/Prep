#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        int count0=0,count1=0;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='0') count0++;
            else count1++;
        }

        int val=0;

        // cout<<count0<<count1<<endl;

        
        for(int i=0; i<s.size(); i++)
        {
            // if(count0 == 0  || count1 ==0) break;

            if(s[i]=='0' && count1!=0)
            {
                count1--;
                val++;
            }
            else if(s[i] =='1' && count0!=0)
            {
                count0--;
                val++;

            } 
            else break;

        }
        // cout<<val<<endl;

        cout<<s.size()-val<<endl;

    }

    return 0;
}
