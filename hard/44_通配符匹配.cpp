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
