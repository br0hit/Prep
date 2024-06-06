#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<int> pow2(200002,0);
    int modval = 1e9 + 7;

    int power = 1;
    pow2[0] = 1;
    for (int i = 1; i <= 2*100000; i++)
    {
        power = (2 * pow2[i - 1]);
        if(power>modval) power = power%modval;
            pow2[i] = power;
    }

    while (t--)
    {   
        int n,k;
        cin>>n>>k;


        vector<int> arr(n,0);
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        int max_sum=arr[0], curr_sum=arr[0], arr_sum=arr[0];
        for(int i=1; i<n; i++)
        {
            arr_sum+=arr[i];
            if(curr_sum>0) curr_sum = curr_sum+arr[i];
            else curr_sum = arr[i];

            if(curr_sum>max_sum) max_sum = curr_sum;
        }

        if(max_sum<0) max_sum=0;

        int finalsum;

        finalsum = arr_sum + (pow2[k]-1)*max_sum;

        if(finalsum>=0) cout<<finalsum%modval<<endl;
        else
        {
            int count =1;
            int ans = finalsum + count * modval;
            while (finalsum + count * modval <= 0)
            {
                count++;
            }
            cout << finalsum + count * modval << endl;
        }
    }

    return 0;
}