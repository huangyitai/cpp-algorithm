#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int ans = 0;
        for(int i=0, j=len-1; i<j; ) {
            int area = min(height[i], height[j]) * (j-i);
            if(ans < area) {
                ans = area;
            }
            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // 测试用例 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result1 = solution.maxArea(height1);
    cout << "Test Case 1 Result: " << result1 << endl;

    // 测试用例 2
    vector<int> height2 = {1, 1};
    int result2 = solution.maxArea(height2);
    cout << "Test Case 2 Result: " << result2 << endl;

    // 测试用例 3
    vector<int> height3 = {4, 3, 2, 1, 4};
    int result3 = solution.maxArea(height3);
    cout << "Test Case 3 Result: " << result3 << endl;

    // 其他测试用例...

    return 0;
}