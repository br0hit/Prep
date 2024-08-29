#include <iostream>
#include <vector>
#include <set>

using namespace std;

string solution(vector<vector<int>> &instructions)
{
    string r = "";
    set<int> obstacles;

    for (const auto &instruction : instructions)
    {
        if (instruction[0] == 1)
        {
            // Add obstacle at the given position
            obstacles.insert(instruction[1]);
        }
        else
        {
            int x = instruction[1];
            int size = instruction[2];

            int val1 = x-1;
            int val2 = x-size;

            if(val1>0 && val2>0)
            {

                auto u = obstacles.lower_bound(val1);
                auto v = obstacles.lower_bound(val2);
            }



            if(v ==u) r+= '1';
            else r+='0';

            // if (obstacles.find(x) != obstacles.end())
            // {
            //     r += '0';
            // }
            // else
            // {
            //     // Find the smallest element in the set that is greater than x
            //     auto it = obstacles.upper_bound(x);

            //     // Check if the block can fit without intersecting an obstacle
            //     if (it != obstacles.end() && *it < x + size)
            //     {
            //         r += '0';
            //     }
            //     else
            //     {
            //         r += '1';
            //     }
            // }
        }
    }

    return r;
}

int main()
{
    vector<vector<int>> instructions = {
        {1, 2},
        {1, 5},
        {2, 5, 2},
        {2, 2, 1},
        {2, 6, 3},
        {2, 3, 2}};

    string output = solution(instructions);
    cout << "Output: " << output << endl; // Should print "1010"

    return 0;
}
