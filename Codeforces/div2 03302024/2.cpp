#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin>>n;

        vector<int> a(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<int> p(n,0);
        vector<int> ascend(n,0);
        priority_queue<int, vector<int>, greater<int>> minheap;
        int count=0;

        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                if(a[i]==1)
                {
                    ascend[i] = 0;
                    minheap.push(0);
                    count++;

                    cout<<0<<" ";
                }
                else
                {
                    ascend[i] = -1*a[i];
                    minheap.push(-1*a[i]);
                    cout<<ascend[i]<<" ";
                }
            }
            else
            {

                if(a[i]==1)
                {
                    int temp;
                    int mex = minheap.top();
                    if(mex==0)
                    {
                        count++;
                        temp = a[i] * -1 + count;
                    }
                    else
                    {
                      temp=0;
                      count++;
                    }

                    cout << temp << " ";
                    minheap.push(temp);
                }
                else if(a[i]>1)
                {
                    int mex= minheap.top();
                    int temp = n-a[i];

                    cout << temp << " ";
                    minheap.push(temp);
                }
                else
                {
                    int mex = minheap.top();
                    if (mex != 0)
                        mex = 0;
                        else
                        mex = count;
                    int temp = a[i] * -1 + mex;
                    cout << temp << " ";
                    minheap.push(temp);
                }
            }
        }

        cout<<endl;

    }

}