#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
   int trap(vector<int>& height) {
        int ans = 0, i = 0, j = height.size()-1;
        int iLeftMax = 0, jRightMax = 0;
        while(i < j) {
            iLeftMax = max(height[i], iLeftMax);
            jRightMax = max(height[j], jRightMax);
            if(height[i] < height[j]) {
                // 这里肯定了 iLeftMax < jRightMax
                // 因为 height[i] < height[j], i 才会做 ++
                // i的移动说明就算 height[i] = iLeftMax，也是比不上 jRightMax 的
                ans += iLeftMax - height[i];
                ++i;
            } else {
                // 这里肯定了 iLeftMax > jRightMax
                // 因为 height[i] > height[j], j 才会做 --
                // j的移动说明就算 height[j] = jRightMax，也是比不上 iLeftMax 的
                ans += jRightMax - height[j];
                --j;
            }
        }
        return ans;
    }
};

class Solution1 {
public:
   int trap(vector<int>& height) {
        int ans = 0, i = 0, j = height.size()-1;
        int iLeftMax = 0, jRightMax = 0;
        while(i < j) {
            iLeftMax = max(height[i], iLeftMax);
            jRightMax = max(height[j], jRightMax);
            if(height[i] < height[j]) {
                if(iLeftMax < jRightMax) {
                    ans += iLeftMax - height[i];
                } else {
                    ans += jRightMax - height[i];
                }
                ++i;
            } else {
                if(iLeftMax < jRightMax) {
                    ans += iLeftMax - height[j];
                } else {
                    ans += jRightMax - height[j];
                }
                --j;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // 测试用例1
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result1 = solution.trap(height1);
    cout << "Test Case 1 Result: " << result1 << endl;

    // 测试用例2
    vector<int> height2 = {4,2,0,3,2,5};
    int result2 = solution.trap(height2);
    cout << "Test Case 2 Result: " << result2 << endl;

    // 可以根据需要添加更多的测试用例

    return 0;
}