#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = x;
        int ans = 0;
        while(left <= right) {
            long long mid = (left + right) / 2;
            if(mid * mid < x) {
                left = mid + 1;
            } else if (mid * mid >= x) {
                right = mid - 1;
            }
            if((mid * mid < x && (mid+1)*(mid+1)>x) || (mid*mid == x)) {
                ans = mid;
                break;
            } 
        }
        return ans;
    }
};

#include <iostream>

int main() {
    Solution solution;

    // 测试用例1
    int x1 = 4;
    int result1 = solution.mySqrt(x1);
    std::cout << "sqrt(" << x1 << ") = " << result1 << std::endl;

    // 测试用例2
    int x2 = 8;
    int result2 = solution.mySqrt(x2);
    std::cout << "sqrt(" << x2 << ") = " << result2 << std::endl;

    // 测试用例3
    int x3 = 1;
    int result3 = solution.mySqrt(x3);
    std::cout << "sqrt(" << x3 << ") = " << result3 << std::endl;

    return 0;
}
