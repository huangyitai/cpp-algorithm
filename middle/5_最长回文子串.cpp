#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    static const int maxn = 1000+5;
    bool **dp;
    string longestPalindrome(string s) {
        int len = s.size();
        dp = new bool*[len];
        for(int i=0; i<len; i++) {
            dp[i] = new bool[len];
        }
        for(int i=0; i<s.size(); i++) {
            dp[i][i] = true;
        }
        int ans = 0;
        int ansl=0, ansr=0;
        // dp的思想是用中心扩散法，dp[i][j] = dp[i+1][j-1], 所以这个递推关系要求逆着遍历数组
        for(int i=len-1; i>=0; i--) {
            for(int j=len-1; j>=i; j--) {
                if(s[i] == s[j]) {
                    if(j - i == 1) {
                        dp[i][j] = true;
                    } else if(i+1 <= j-1 && i+1<len && j-1 > 0) {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if(dp[i][j] && j-i+1>ans) {
                    ansl = i, ansr = j;
                    ans = j-i+1;
                }
            }
        }
        return s.substr(ansl, ans);
    }
};

int main() {
    Solution solution;

    // 测试用例1
    std::string testStr1 = "a";
    std::string result1 = solution.longestPalindrome(testStr1);
    std::cout << "Test Case 1: " << testStr1 << " -> " << result1 << std::endl;

    memset(solution.dp,0,sizeof(solution.dp));
    // 测试用例2
    std::string testStr2 = "cbbd";
    std::string result2 = solution.longestPalindrome(testStr2);
    std::cout << "Test Case 2: " << testStr2 << " -> " << result2 << std::endl;

    // 可以根据需要添加更多的测试用例

    return 0;
}
