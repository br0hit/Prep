#include <iostream>
using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int temp;

        if(a>b)
        {
            temp=a;
            a=b;
            b=temp;
        }

        if(c>d)
        {
            temp=c;
            c=d;
            d=temp;
        }

        temp =-1;

        for(int i=1; i<=12; i++)
        {
            if(i==a) temp=0;

            if(i==c) c=temp;

            if(i==b) temp=-1;

            if(i==d) d=temp;
        }

        if(c==d)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else cout<<"yes"<<endl;
        
    }

    return 0;
}