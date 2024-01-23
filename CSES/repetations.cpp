#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int n;
    string s;
    cin>>s;
    n = s.size();
    char temp,tempminus1=s[0];
    long long int currsum=1,maxsum=1;


    for(int i=1; i<n; i++)
    {
        temp = s[i];
 
        if(temp == tempminus1)
        {
            currsum++;
        }
        else
        {
            if(currsum>maxsum)
            {
                maxsum = currsum;
            } 
            currsum = 1;
            tempminus1 = temp;
        }
    }

                if(currsum>maxsum)
            {
                maxsum = currsum;
            } 

    cout<<maxsum;
    return 0;
}