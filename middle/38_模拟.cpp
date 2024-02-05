#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string now = "1";
        string s;
        while(--n) {
            s = now;
            now = "";
            int cnt = 0;
            char pre = s[0];
            for(int i=0; i<s.size(); i++) {
                if(pre == s[i]) {
                    cnt ++;

                } else {
                    now = now + char(cnt + '0') + pre;
                    cnt = 1;
                    pre = s[i];
                }
            }
            now = now + char(cnt + '0') + pre;
        }
        return now;
    }
};

int main() {
    Solution solution;

    // 测试用例1
    int n1 = 1;
    std::string result1 = solution.countAndSay(n1);
    std::cout << "Test Case 1: n = " << n1 << ", Result: " << result1 << std::endl;

    // 测试用例2
    int n2 = 4;
    std::string result2 = solution.countAndSay(n2);
    std::cout << "Test Case 2: n = " << n2 << ", Result: " << result2 << std::endl;

    // 测试用例3
    int n3 = 6;
    std::string result3 = solution.countAndSay(n3);
    std::cout << "Test Case 3: n = " << n3 << ", Result: " << result3 << std::endl;

    // 可以根据需要添加更多的测试用例

    return 0;
}