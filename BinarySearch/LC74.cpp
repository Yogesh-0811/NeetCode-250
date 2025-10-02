// 74. Search a 2D Matrix
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int mid_val = matrix[mid / n][mid % n];
            if(mid_val == target) return true;
            else if(mid_val < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

int main() {
    int m, n, target;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter matrix elements row-wise:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter target: ";
    cin >> target;

    Solution sol;
    bool found = sol.searchMatrix(matrix, target);

    if(found) cout << "Target found \n";
    else cout << "Target not found \n";

    return 0;
}
