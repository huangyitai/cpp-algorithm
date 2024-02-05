#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, len = nums.size();
        if(len == 1) {
            return 0;
        }
        for(int i = 0; i < len; ) {
            int j, next = 0, farPos = 0;
            // 贪心
            // 当前在i, 可以跳到j步, 到[i+1, i+j]
            // 取 max{ i + j + nums[i+j] }, j={ 1..nums[i] }, 其中最大的j，就是当前i要跳j步，到达next = i+j的地方。
            for(j = 1; j <= nums[i]; j++) {
                if(i + j >= len - 1) return ans + 1;
                if(i + j < len && i + j + nums[i+j] >= farPos) {
                    farPos = i + j + nums[i+j];
                    next = i + j;
                }
            }
            i = next;
            ans ++;
        }
        return 0; 
    }
};

int main() {
    Solution s;

    vector<int> nums = {3,2,1};
    cout<<"ans: "<<s.jump(nums)<<endl<<"=========="<<endl;

    nums = {2,3,1,1,4};
    cout<<"ans: "<<s.jump(nums)<<endl<<"=========="<<endl;

    nums = {2,3,0,1,4};
    cout<<"ans: "<<s.jump(nums)<<endl<<"=========="<<endl;

    nums = {1};
    cout<<"ans: "<<s.jump(nums)<<endl<<"=========="<<endl;

    nums = {0};
    cout<<"ans: "<<s.jump(nums)<<endl;

    return 0;
}