#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> getWeights(const vector<vector<int>>& matrix) {
    vector<pair<int, int>> weights;
    int size = matrix.size() - 1;
    
    for (int i = 0; i <= size; i++) {
        int key = matrix[i][0];
        int weight = 0;
        
        for (int j = 0; j <= size; j++) {
            if (i == 0) {
                weight += matrix[j][j];
            } else if (i == size) {
                weight += matrix[size - j][j];
            } else {
                int diagonalUp = abs(j - i);
                int diagonalDown = size - (abs(size - (i + j)) % size);
                weight += matrix[diagonalUp][j];
                weight += matrix[diagonalDown][j];
            }
        }
        weights.push_back({key, weight});
    }
    return weights;
}

vector<int> solution(vector<vector<int>> matrix) {
    vector<pair<int, int>> weights = getWeights(matrix);
    
    sort(weights.begin(), weights.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });
    
    vector<int> result;
    for (const auto& pair : weights) {
        result.push_back(pair.first);
    }
    
    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 2, 5},
        {3, 2, 5, 0},
        {9, 0, 1, 3},
        {6, 1, 0, 8}
    };
    
    vector<int> result = solution(matrix);
    
    cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}