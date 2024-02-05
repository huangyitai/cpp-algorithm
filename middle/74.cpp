#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size()-1;
        // 查找右边界
        while(left < right) {
            int mid = ((left + right) >> 1) + 1;
            if(matrix[mid][0] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int row;
        if(matrix[left][0] <= target) {
            row = left;
        } else {
            return false;
        }
        left = 0, right = matrix[0].size() - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(matrix[row][mid] > target) {
                right = mid - 1;
            } else if(matrix[row][mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // 测试用例1
    std::vector<std::vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int target1 = 3;
    bool result1 = solution.searchMatrix(matrix1, target1);
    std::cout << "Test Case 1: " << (result1 ? "true" : "false") << std::endl;

    // 测试用例2
    std::vector<std::vector<int>> matrix2 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int target2 = 13;
    bool result2 = solution.searchMatrix(matrix2, target2);
    std::cout << "Test Case 2: " << (result2 ? "true" : "false") << std::endl;

    // 添加更多的测试用例...

    return 0;
}