#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int p1,p2,p3;
        cin>>p1>>p2>>p3;

        int count;

        if((p1+p2+p3)%2==1)
        {
            count = -1;
        } 
        else
        {
            if(p1+p2>p3)
            {
                int diff = ((p1+p2)-p3)/2;
                count = diff + p3;
            }
            else
            {
                count = p1+p2;
            }
        }

        cout << count << endl;
    }

    return 0;
}