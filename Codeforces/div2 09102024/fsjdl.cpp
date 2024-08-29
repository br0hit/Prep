#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

string solution(vector<vector<int>> operations)
{
    set<int> obstacles;
    string result;

    for (const auto &op : operations)
    {
        if (op[0] == 1)
        {
            // Build an obstacle
            obstacles.insert(op[1]);
        }
        else if (op[0] == 2)
        {
            // Check if a block can be built
            int x = op[1];
            int size = op[2];
            bool canBuild = true;

            for (int i = x - size; i < x; ++i)
            {
                if (obstacles.find(i) != obstacles.end())
                {
                    canBuild = false;
                    break;
                }
            }

            result += canBuild ? "1" : "0";
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> operations = {
        {1, 2},
        {1, 5},
        {2, 5, 2},
        {2, 2, 1},
        {2, 6, 3},
        {2, 3, 2}};

    string output = solution(operations);
    cout << "Output: " << output << endl;

    return 0;
}