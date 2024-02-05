#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows[7] = {0}, cols[7] = {0};
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j]==0) {
                    rows[i/32] |= 1 << (i%32);
                    cols[j/32] |= 1 << (j%32);
                }
            }
        }
        for(int i=0; i<m; i++) {
            if(rows[i/32] & (1<<(i%32))) {
                for(int j=0; j<n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j=0; j<n; j++) {
            if(cols[j/32] & (1<<(j%32))) {
                for(int i=0; i<m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    Solution solution;

    // 测试用例1
    std::vector<std::vector<int>> matrix1 = {{1, 2, 3}, {4, 0, 6}, {7, 8, 9}};
    solution.setZeroes(matrix1);
    std::cout << "测试用例1结果：" << std::endl;
    for (const auto& row : matrix1) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // 测试用例2
    std::vector<std::vector<int>> matrix2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    solution.setZeroes(matrix2);
    std::cout << "测试用例2结果：" << std::endl;
    for (const auto& row : matrix2) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}