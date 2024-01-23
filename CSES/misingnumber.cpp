#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main()
{
    long long int n,sum=0,temp1,temp2;
    cin>>n;
    vector<int> temp(n-1,0);
    temp2 = (n*(n+1))/2;

    while(--n)
    {
        cin>>temp1;
        sum += temp1;

    }
    long long int answer;

    answer =  temp2- sum;
    cout<<answer;

    return 0;

}