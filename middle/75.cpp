#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>& nums, int st, int ed) {
        int tempSt = st, tempEd = ed;
        int flag = st;
        int flagVal = nums[st];
        while(st < ed) {
            while(nums[st] <= flagVal) {
                st ++;
            }
            while(nums[ed] >= flagVal) {
                ed --;
            }
            nums[flag] = nums[ed];
            nums[ed] = nums[st];
            flag = st;
        }
        nums[st] = flagVal;
        quickSort(nums, tempSt, st-1);
        quickSort(nums, st+1, tempEd);
    }

    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size());
    }
};

int main() {
    Solution solution;

    // 构造测试数组
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // 输出原始数组
    cout << "Original Array: ";
    solution.printArray(nums);

    // 调用排序函数
    vector<int> sortedArray = solution.sortArray(nums);

    // 输出排序后的数组
    cout << "Sorted Array: ";
    solution.printArray(sortedArray);

    return 0;
}