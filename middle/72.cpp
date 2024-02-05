#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int dp[520][520];
    int minDistance(string word1, string word2) {
        memset(dp, 0, sizeof(dp));
        int len1 = word1.size();
        int len2 = word2.size();
        for(int i=0; i<=len1; i++) {
            dp[i][0] = i;
        }
        for(int j=0; j<=len2; j++) {
            dp[0][j] = j;
        }
        word1 = " " + word1;
        word2 = " " + word2;
        for(int i=1; i<=len1; i++) {
            for(int j=1; j<=len2; j++) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1])) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};

int main() {
    string s1 = "intention";
    string s2 = "execution";

    Solution s;
    cout<<s.minDistance(s1,s2)<<endl;
    return 0;
}