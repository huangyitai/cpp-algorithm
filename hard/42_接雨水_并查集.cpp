#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

// 并查集
class Solution {
public:
    int *leftMax;
    int *rightMax;
    // 并查集 get
    int getLeftMax(int x) {
        return x == leftMax[x] ? x : leftMax[x] = getLeftMax(leftMax[x]);
    }
    int getRightMax(int x) {
        return x == rightMax[x] ? x : rightMax[x] = getRightMax(rightMax[x]);
    }

    int trap(vector<int>& height) {
        int len = height.size();
        // 初始化并查集
        leftMax = new int[len];
        rightMax = new int[len];
        for(int i=0; i<len; i++) {
            leftMax[i] = i, rightMax[i] = i;
        }
        // 记录从左到当前值的最大
        for(int i=1; i<len; i++) {
            if(height[getLeftMax(i-1)] > height[i]) {
                leftMax[i] = getLeftMax(i-1);  
            }
        }
        // 记录从右到当前值的最大
        for(int i=len-2; i>=0; i--) {
            if(height[getRightMax(i+1)] > height[i]) {
                rightMax[i] = getRightMax(i+1);  
            }
        }
        int ans = 0;
        for(int i=0; i<len; i++) {
            ans += min(height[getRightMax(i)], height[getLeftMax(i)]) - height[i];
        }        
        return ans;
    }
};




int main() {
    Solution solution;
    
    // 测试用例1
    // vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    // int result1 = solution.trap(height1);
    // cout << "Test Case 1 Result: " << result1 << endl;

    // 测试用例2
    vector<int> height2 = {4,2,0,3,2,5};
    int result2 = solution.trap(height2);
    cout << "Test Case 2 Result: " << result2 << endl;

    // 可以根据需要添加更多的测试用例

    return 0;
}