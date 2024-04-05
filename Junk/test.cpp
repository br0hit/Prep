#include<iostream>

using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        long long x,init;
        int k;

        cin>>x>>k;

        init = x;

        long long i,y;
        int sum;
        long long temp=0;

        sum =0;

        while(x>0)
        {
            sum = sum + x%10;
            x = x/10;
        }

        // cout<<sum<<endl;

        if(sum%k!=0)
        {
            temp = k - sum%k;
        }

        y = init + temp;

        cout<<y<<endl;
    }

    return 0;
}