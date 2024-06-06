#include <bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int> &arr, int n)
{
    // Write your code here.

    vector<vector<int>> dp(n, vector<int>(4, 0));

    if (n == 1)
        return 1;
    if (n == 2)
    {
        if (arr[0] == arr[1])
            return 1;

        return 2;
    }

    dp[0][0] =1;
    dp[0][1] =0;


    if (arr[0] == arr[1])
    {
        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[1][2] = 1;
        dp[1][3] 
    }
    else
    {
        dp[1][0] = 2;
        if(arr[1]<arr[0]) dp[1][1] = 1;
        else dp[1][1]=0;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " " << dp[i][0] << " " << dp[i][1];
    //     cout << endl;
    // }

    int tempmax, maxvall, tempval, val;

    for (int i = 2; i < n; i++)
    {
        tempmax = maxvall = tempval = val = -1;

        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j][1] == 0)
            {
                if (arr[i] > arr[j])
                {
                    tempmax = dp[j][0]+1;
                    tempval = 0;
                }
                else if (arr[i] == arr[j])
                {
                    tempval = 0;
                    tempmax = 1;
                }
                else
                {
                    tempval = 1;
                    tempmax = dp[j][0]+1;
                }
            }
            else
            {
                if (arr[i] < arr[j])
                {
                    tempval = 1;
                    tempmax = 1+dp[j][0];
                }
                else
                {
                    tempval = 0;
                    tempmax = 1;
                }
            }

            if (tempmax > maxvall)
            {
                maxvall = tempmax;
                val = tempval;
            }

            if(tempmax==maxvall && tempval==0) val=0;
        }

        dp[i][0] = maxvall;
        dp[i][1] = val;
        // cout<<"here"<<i<<endl;
    }

    int maxval = -1;

    for (int i = 0; i < n; i++)
    {
        maxval = max(maxval, dp[i][0]);
        cout<<1+i<<" "<<dp[i][0]<<" "<<dp[i][1];
        cout<<endl;
    }

    return maxval;
}

int main()
{
    vector<int> arr = {20,11,8,17,38,25,41,22,32,46,34};
    int n = 11;

    int retval = longestBitonicSubsequence(arr, n);
    cout << retval;
}
