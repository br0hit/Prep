class Solution
{
public:
    int findcount(vector<vector<int>> &matrix, int row, int C, int val)
    {
        // cout<<"Finding cout of "<<val<<" In row ";

        int lo = 0;
        int hi = C - 1;
        int ans = -1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (matrix[row][mid] > val)
            {
                hi = mid - 1;
            }
            else
            {
                ans = mid;
                lo = mid + 1;
            }
        }
        // cout<<row<<" "<<ans+1<<endl;
        return ans + 1;
    }

    int countval(vector<vector<int>> &matrix, int R, int C, int val)
    {
        int totalcount = 0;
        for (int i = 0; i < R; i++)
        {
            totalcount += findcount(matrix, i, C, val);
        }

        if (totalcount - 1 >= R * C - totalcount)
        {
            if (totalcount - 1 == R * C - totalcount + 1)
                return 2;
            return 1;
        }
        return 0;
    }

    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // code here

        int minval = 1, maxval = 2000;
        int lo = minval;
        int hi = maxval;
        int ans;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int temp = countval(matrix, R, C, mid);
            if (temp)
            {
                ans = mid;
                if (temp == 2)
                    return ans;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
