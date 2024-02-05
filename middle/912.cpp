#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>& nums, int st, int ed) {
        if(st >= ed) return;
        int tempSt = st, tempEd = ed;
        // 关键点1
        int flag = rand() % (ed - st + 1) + st;
        swap(nums[st], nums[flag]);
        int flagVal = nums[st];
        while(st < ed) {
            while(nums[ed] > flagVal && st < ed) {
                --ed;
            }
            if(st == ed) {
                break;
            }
            nums[st] = nums[ed];
            while(nums[st] <= flagVal && st < ed) {
                ++st;
            }
            if(st == ed) {
                break;
            }
            nums[ed] = nums[st];
        }
        nums[st] = flagVal;
        // 关键点2
        while(st > 0 && nums[st]==nums[st-1]) --st;
        while(ed < tempEd && nums[ed] == nums[ed+1]) ++ed;
        quickSort(nums, tempSt, st-1); 
        quickSort(nums, ed+1, tempEd);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }

    void printArray(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            cout<<nums[i]<<' ';
        }
        cout<<endl;
    }
};

int main() {
    Solution solution;

    // 构造测试数组
    vector<int> nums = {5,3,2,3,1,5,5,9,8,7,4};

    // 输出原始数组
    cout << "Original Array: ";
    solution.printArray(nums);

    // 调用排序函数
    solution.sortArray(nums);
    // 输出排序后的数组
    cout << "Sorted Array: ";
    solution.printArray(nums);

    return 0;
}