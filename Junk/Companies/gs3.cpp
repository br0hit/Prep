#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int rollDice(int R, int C)
{
    int top = 1, east = 3, south = 2;
    int totalSum = 0;

    for (int row = 0; row < R; ++row)
    {
        if (row % 2 == 0)
        { // Moving right
            for (int col = 0; col < C; ++col)
            {
                cout<<top<<endl;
                totalSum += top;
                if (col < C - 1)
                {
                    int temp = top;
                    top = 7 - east;
                    east = temp;
                }
            }
        }
        else
        { // Moving left
            for (int col = C - 1; col >= 0; --col)
            {
                cout << top << endl;
                totalSum += top;
                if (col > 0)
                {
                    int temp = top;
                    top = east;
                    east = 7 - temp;
                }
            }
        }

        // Roll down to next row
        if (row < R - 1)
        {

            int temp = top;
            top = 7 - south;
            south = top;

        }
    }

    return totalSum;
}

int main()
{
    int R, C;
    std::cin >> R >> C;

    int result = rollDice(R, C);
    std::cout << result << std::endl;

    return 0;
}
