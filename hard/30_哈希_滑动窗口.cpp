#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool check(vector<string>& words, unordered_map<string,int> checker) {
        for(int i=0; i<words.size(); i++) {
            if(checker[words[i]] > 0) {
                checker[words[i]] --;
            } else {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int m = words.size();
        int n = words[0].size();
        
        // n个不同的起点
        // 原因是因为每个word长度一样, 每次都跳一个n = len(word), 所以要有n个起点去跳
        // winb (windows begin), segb (segment begin), sege (segment end)
        for(int winb = 0; winb < n; winb ++) {
            unordered_map<string, int> checker;
            int first = 0;
            for(int segb=winb, sege=winb+n*m-1; sege < s.size(); segb+=n, sege+=n) {
                string newWord = s.substr(sege-n+1,n);
                string preWord = s.substr(segb,n);
                if(first == 0)  {
                    for(int i=segb; i<=sege; i+=n) {
                        checker[s.substr(i, n)] ++;
                    }
                    first = 1;
                    for(int i=0; i<words.size(); i++) {
                        if(--checker[words[i]] == 0) {
                            checker.erase(words[i]);
                        } 
                    }
                } else {
                    if(++checker[newWord] == 0) {
                        checker.erase(newWord);
                    }
                } 
                // 判断子串是否合法，合法则记录答案
                if(checker.empty()) {
                    ans.push_back(segb);
                }
                if(--checker[preWord] == 0) {
                    checker.erase(preWord);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // 测试用例1
    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};
    vector<int> result1 = solution.findSubstring(s1, words1);

    cout << "Test Case 1 Result: ";
    for (int idx : result1) {
        cout << idx << " ";
    }
    cout << endl;

    // 测试用例2
    string s2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word", "good", "best", "word"};
    vector<int> result2 = solution.findSubstring(s2, words2);

    cout << "Test Case 2 Result: ";
    for (int idx : result2) {
        cout << idx << " ";
    }
    cout << endl;

    // 添加更多的测试用例...

    return 0;
}