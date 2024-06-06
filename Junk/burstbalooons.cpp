#include <bits/stdc++.h>
using namespace std;
int maxCoins(vector<int> &nums)
{

    if (nums.size() == 1)
        return nums[0];

    int maxval = -1e9;

    for (int i = 0; i < nums.size(); i++)
    {
        int popval;
        vector<int> newnums;
        for (int j = 0; j < nums.size(); j++)
        {
            if(j!=i)
            newnums.push_back(nums[j]);
        }

        int val1,val3;
        if (i - 1 < 0)
            val1 = 1;
        else
            val1 = nums[i - 1];
        if (i + 1 >= nums.size())
            val3 = 1;
        else
            val3 = nums[i + 1];
        popval = nums[i] * val1 * val3;
        cout<<"testing"<<i<<newnums.size()<<endl;
        maxval = max(maxval, maxCoins(newnums) + popval);
    }

    return maxval;
}

int main()
{
    vector<int> nums = {3, 1,5,8};
    int ans = maxCoins(nums);
    cout<<ans<<endl;

    int len = nums.size();
    vector<vector<int>> dp(len+1, vector<int>(len+1,0));

    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            dp[i,j] = 
        }
    }



}