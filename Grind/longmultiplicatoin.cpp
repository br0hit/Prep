#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int intval(char x)
{
    return x-'0';
}



int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string x,y;
        cin>>x>>y;

        int len = x.size();

        int first=0,second=0;

        for(int i=0; i<len; i++)
        {
            if(x[i]!=y[i])
            {
                if(first==0)
                {
                    first = 1;
                    second = i;
                } 
                else
                {
                    if(x[second]>y[second])
                    {
                        if(x[i]>y[i])
                        {
                            char tempchar = x[i];
                            x[i] = y[i];
                            y[i] = tempchar;
                        }
                    }
                    else
                    {
                        if(y[i]>x[i])
                        {
                            char tempchar = x[i];
                            x[i] = y[i];
                            y[i] = tempchar;
                        }
                    }
                }
            }
        }


        cout<<x<<endl<<y<<endl;


    }

    return 0;
}