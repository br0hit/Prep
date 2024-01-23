#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        string s;

        cin>>n;
        cin>>s;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!=s[i+1])
            {
                s.erase(i,2);
                //s.erase(i+1,1);
            }
        }


    }

    return 0;
}
