#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        int n = height.size();
        for(int i=0; i<n; i++) {
            if(st.empty()) {
                st.push(i);
                continue;
            } 
            while(!st.empty()) {
                int top = st.top();
                if(height[top] >= height[i]) {
                    st.push(i);
                    break;
                }
                st.pop();
                if(st.empty()) {
                    st.push(i);
                    break;
                }
                int left = st.top();
                ans += (min(height[left], height[i]) - height[top]) * (i-left-1);
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