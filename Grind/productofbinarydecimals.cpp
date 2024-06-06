#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int checkval(vector<int> &arr, int val)
{
    for(int i=0; i<arr.size(); i++)
    {
        if(val%arr[i]==0)
        {
            int newval = val/arr[i];
            int tempans = checkval(arr, newval);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    int val=1;

    vector<int> arr =   {1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111,10000,10001,10010,10011,10100,10101,10110,10111,11000,11001,11010,11011,11100,11101,11110,11111,100000};

    while (t--)
    {
        int n;
        cin>>n;

        int finalans=0,breakpoint=0;
        int tempn;

        for(int i=0; i<arr.size(); i++)
        {
            tempn = n;
            if(tempn%arr[i]==0)
            {
                while(tempn)
            }
        }



        if(finalans==1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }

    return 0;
}