#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n,k;
        cin>>n>>k;

        vector<int> a(2*n,0);

        for(int i=0;i<2*n;i++)
        {
            cin>>a[i];
        }

        vector<int> first(n,0),second(n,0), final(n,0);
        int count=0,print_count,temp,temp1;

        for(int i=0; i<n; i++)
        {
            first[a[i]-1]++;

            if(first[a[i]-1]==2) count++;
        }

        for (int i = n; i < 2*n; i++)
        {
            second[a[i]-1]++;
        }

        // for(int i=0; i<n; i++)
        // {
        //     cout<<first[i];
        // }
        // cout<<endl;

        // for (int i = 0; i < n; i++)
        // {
        //     cout << second[i];
        // }
        // cout<<"count"<<count;

        print_count=0;
        temp=0;
        temp1=0;
    

        if(count>=k)
        {
            print_count = 0;
            for(int i=0; i<n; i++)
            {
                if(first[i]==2){
                    cout << i + 1 << " " << i + 1 << " ";
                    print_count += 2;
                    if (print_count >= 2 * k)
                        break;
                }

            }cout<<endl;
            // cout<<"HERE";

            print_count = 0;
            for (int i = 0; i < n; i++)
            {
                if (second[i] == 2)
                {
                    cout << i + 1 << " " << i + 1 << " ";
                    print_count += 2;
                    if (print_count >= 2 * k)
                        break;
                }
            }
        }

        else
        {
            print_count = 0;
            temp=0;
            for (int i = 0; i < n; i++)
            {
                if (first[i] == 2)
                {
                    cout << i + 1 << " " << i + 1<<" ";
                    print_count += 2;
                    if (print_count >= 2 * k)
                        break;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (print_count >= 2 * k)
                {
                    break;
                }
                if (first[i] == 1)
                {
                    cout << i + 1<<" ";
                    print_count += 1;
                    final[temp] = i+1;
                    temp++;

                }
            }
            cout<<endl;

            for (int i = 0; i < n; i++)
            {
                if (second[i] == 2)
                {
                    cout<< i + 1 << " " << i + 1<<" ";
                    // print_count += 2;
                    // if (print_count >= 2 * k)
                    //     break;
                }
            }
            for (int i = 0; i < temp; i++)
            {
                    cout <<final[i]<<" ";
                    // if (print_count >= 2 * k)
                    //     break;
            }
            cout<<endl;
        }
    }
}
