#include<iostream>
#include<string>
#include<vector>
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

    int maxArea(vector<int>& height) {
        int len = height.size();
        // 初始化并查集
        leftMax = new int[len];
        rightMax = new int[len];
        for(int i=0; i<len; i++) {
            leftMax[i] = i, rightMax[i] = i;
        }
        // 记录从左到当前值的最大
        for(int i=1; i<len; i++) {
            if(height[getLeftMax(i-1)] >= height[i]) {
                leftMax[i] = getLeftMax(i-1);  
            }
        }
        // 记录从右到当前值的最大
        for(int i=len-2; i>=0; i--) {
            if(height[getRightMax(i+1)] >= height[i]) {
                rightMax[i] = getRightMax(i+1);  
            }
        }
        for(int i=0; i<len; i++) {
            cout<<height[getLeftMax(i)]<<' ';
        }
        cout<<endl;
        for(int i=0; i<len; i++) {
            cout<<height[getRightMax(i)]<<' ';
        }
        cout<<endl;
        int ans = 0;
        for(int i=0; i<len; i++) {
            int tmp = (getRightMax(i) - getLeftMax(i)) * min(height[getLeftMax(i)], height[getRightMax(i)]);
            if(ans < tmp) {
                ans = tmp;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // 测试用例 1
    // vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // int result1 = solution.maxArea(height1);
    // cout << "Test Case 1 Result: " << result1 << endl;

    // 测试用例 2
    vector<int> height2 = {1, 2, 1};
    int result2 = solution.maxArea(height2);
    cout << "Test Case 2 Result: " << result2 << endl;

    // 测试用例 3
    vector<int> height3 = {4, 3, 2, 1, 4};
    int result3 = solution.maxArea(height3);
    cout << "Test Case 3 Result: " << result3 << endl;

    // 其他测试用例...

    return 0;
}