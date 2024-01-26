#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> weights(n,0);
    long long w1,w2,minw=1e9,currw;

    for(int i=0; i<n; i++) cin>>weights[i];

    for(int i=0; i<pow(2,n); i++)
    {
        int temp=i;
        w1 = 0;
        w2 =0;
        for(int j=0;j<n;j++)
        {   
            if(temp%2==0)
            {
                w1+=weights[j];
            }
            else w2+=weights[j];
            temp = temp/2;
        }
        
        currw = w1-w2;
        if(currw<0) currw*=-1;

        if(currw<minw) minw = currw;
    }

    cout<<minw;
}