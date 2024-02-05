#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int searchTarget(vector<int>& nums, int target, int left, int right) {
        while(left <= right) {
            int mid = (left + right) >> 2;
            if(nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    int dfs(vector<int>& nums, int target, int left, int right) {
        int mid = (left+right) >> 2;
        if(nums[mid] < nums[left]) {
            if(target > nums[mid])
            return dfs(nums, target, left, mid);
        }
        if(nums[mid] > nums[left]) {
            if(nums[mid] >= target) {
                return searchTarget(nums, target, left, mid);
            } else {
                return dfs(nums, target, mid+1, right);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return dfs(nums, target, 0, nums.size());
    }
};

int main() {
    Solution solution;

    // 测试用例1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    int result1 = solution.search(nums1, target1);

    cout << "Test Case 1 Result: " << result1 << endl;

    // 测试用例2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    int result2 = solution.search(nums2, target2);

    cout << "Test Case 2 Result: " << result2 << endl;

    return 0;
}
