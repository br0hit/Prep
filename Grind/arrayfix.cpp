#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> temp(n, 0);
        vector<int> zero(n,0);

        for (int i = 0; i < n; i++)
        {
            cin >> temp[i];
        }

        int first, second, val, first_new;
        val = 0;

        for (int i = n-2; i >= 0; i--)
        {
            if(zero[i+1]==0)
            {
                if (temp[i] <= temp[i + 1])
                    continue;

                if (temp[i] <= 10)
                {
                    cout<<"no"<<endl;
                    val=1;
                    break;
                }
                else
                {
                    first = temp[i]/10;
                    second = temp[i]%10;
                    zero[i]=1;

                    if(second>temp[i+1] || first>second)
                    {
                        cout << "no" << endl;
                        val=1;
                        break;
                    }
                }
            }
            else
            {
                first_new = temp[i+1]/10;
                if(temp[i] <= first) continue;

                if (temp[i] <= 10)
                {
                    cout << "no" << endl;
                    val=1;
                    break;
                }
                else
                {
                    first = temp[i] / 10;
                    second = temp[i] % 10;
                    zero[i] = 1;

                    if (second > first_new || first > second)
                    {
                        cout << "no" << endl;
                        val=1;
                        break;
                    }
                }
            }
        }

        if(val==0) cout<<"yes"<<endl;

    }
}