#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int a1[120], a2[120], ans[240];
    string multiply(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        // 逆转 string 到 int 数组
        for(int i = l1-1; i>=0; i--){
            a1[l1-i-1] = num1[i] - '0';
        }
        for(int i = l2-1; i>=0; i--){
            a2[l2-i-1] = num2[i] - '0';
        }
        // 双层循环做竖式乘法
        for(int i=0; i<l1; i++) {
            for(int j=0; j<l2; j++) {
                ans[i+j] += a1[i] * a2[j];
            }
        }
        // 处理进位
        for(int i=0; i<235; i++) {
            ans[i+1] += ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
        string anss = "";
        // 转化 int 数组为 string
        int ansLen = l1+l2;
        while(ans[ansLen]==0) {
            ansLen--;
        }
        for(int i=ansLen; i>=0; i--) {
            anss += ans[i]+'0';
        }
        return anss;
    }
};

int main() {
    Solution solution;

    // 测试用例1
    std::string num1_1 = "0";
    std::string num2_1 = "456";
    std::string result1 = solution.multiply(num1_1, num2_1);
    std::cout << "Test Case 1: " << num1_1 << " * " << num2_1 << " = " << result1 << std::endl;

    // 测试用例2
    std::string num1_2 = "987654321";
    std::string num2_2 = "123456789";
    std::string result2 = solution.multiply(num1_2, num2_2);
    std::cout << "Test Case 2: " << num1_2 << " * " << num2_2 << " = " << result2 << std::endl;

    // 可以根据需要添加更多的测试用例

    return 0;
}
