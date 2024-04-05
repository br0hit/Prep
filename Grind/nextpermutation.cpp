#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums={3,2,1};

        vector<int> temp(nums.size(), 0);
        temp = nums;
        int arr_size = nums.size();
        int pos=-1;
        int temp1;

        for (int i = nums.size() - 1; i >= 1; i--)
        {
            if (nums[i]>nums[i-1])
            {
                pos = i;
                break;
            }
        }
        // int pos=i;
        if (pos == -1)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                nums[i] = temp[arr_size - i - 1];
            }

        }
        else
        {
            for (int i = arr_size - 1; i >= pos; i--)
            {
                if (nums[i] > nums[pos - 1])
                {
                    temp1 = nums[i];
                    nums[i] = nums[pos - 1];
                    nums[pos - 1] = temp1;
                    break;
                }
            }

            sort(nums.begin() + pos, nums.end());
        }

        for(int i=0; i<nums.size(); i++)
        {
            cout<<nums[i]<<" ";
        }
}