#include <iostream>
#include <vector>

using namespace std;

// Function to update the dice faces after a roll
void updateDice(int& top, int& right, int& front, char direction) {
    int temp;
    switch (direction) {
        case 'R': // Roll right
            temp = top;
            top = 7 - right;
            right = temp;
            break;
        case 'L': // Roll left
            temp = top;
            top = right;
            right = 7 - temp;
            break;
        case 'D': // Roll down
            temp = top;
            top = 7 - front;
            front = temp;
            break;
    }
}

long long calculateDiceSum(int R, int C) {
    long long sum = 0;
    int top = 1, right = 3, front = 2;
    
    for (int row = 0; row < R; ++row) {
        if (row % 2 == 0) {
            // Moving right
            for (int col = 0; col < C; ++col) {
                cout<<top<<endl;
                sum += top;
                if (col < C - 1) updateDice(top, right, front, 'R');
            }
        } else {
            // Moving left
            for (int col = C - 1; col >= 0; --col) {
                cout<<top<<endl;
                sum += top;
                if (col > 0) updateDice(top, right, front, 'L');
            }
        }
        
        // Move down if not the last row
        if (row < R - 1) updateDice(top, right, front, 'D');
    }
    
    return sum;
}

int main() {
    int R, C;
    cin >> R >> C;
    
    cout << calculateDiceSum(R, C) << endl;
    
 return 0;
}
