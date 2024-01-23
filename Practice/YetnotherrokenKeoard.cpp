#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        vector<int> small,capital;
        string s;

        cin>>s;

        int i=0,j=0;


        for(i=0; i<s.size(); i++)
        {
            if(s[i]=='b')
            {   
                if(!small.empty()) small.pop_back();
            }
            else if(s[i]=='B')
            {
                if(!capital.empty()) capital.pop_back();
            }
            else if(s[i]>='a' && s[i] <= 'z')
            {
                small.push_back(i);
            }
            else capital.push_back(i);
        }

        // while (!small.empty())
        // {
        //     int temp;
        //     cout<<small.back();
        //     small.pop_back();
        // }
        // cout<<endl;
        // i=0;
        // while (i<capital.size())
        // {   
        //     cout<<capital[i]<<" "<<i;
        //     // capital.pop_back();
        //     i++;
        // }
        // cout<<capital.size();

        i=0;
        j=0;


        while(i<small.size() && j<capital.size())
        {
            if(small[i]<capital[j])
            {
                cout<<s[small[i]];
                i++;
            }
            else
            {
                cout<<s[capital[j]];
                j++;

            }
        }
        while(i<small.size())
        {
            cout<<s[small[i]];
            i++;
        }
        while(j<capital.size())
        {
            cout<<s[capital[j]];
            j++;
        }
        cout<<endl;
        
        
    }

    return 0;
}
