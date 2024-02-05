#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;
        while(true) {
            // 边界情况
            if(index1 == m) {
                return nums2[index2 + k - 1];
            }
            if(index2 == n) {
                return nums1[index1 + k - 1];
            }
            if(k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            // s1 被分成两部分，小于pivot1的数有 nums1[0 .. k/2-2] 共计 k/2-1 个
            // s2 被分成两部分，小于pivot2的数有 nums2[0 .. k/2-2] 共计 k/2-1 个
            int newIndex1 = min(index1 + k / 2 - 1, m-1);
            int newIndex2 = min(index2 + k / 2 - 1, n-1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            // 就算s1, s2左边的数都比 pivot1 更小，那么pivot1的排名也只是 k-2
            // 所以要扩大 newIndex1, 缩小 newIndex2
            // 同理对于 pivot2 也是一样的
            if(pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            } else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};

int main(){
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};
    Solution solution;
    cout<<solution.findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}