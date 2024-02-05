#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    // blank 返回长度为 n 的由空格组成的字符串
    string blank(int n) {
        return string(n, ' ');
    }

    // join 返回用 sep 拼接 [left, right) 范围内的 words 组成的字符串
    string join(vector<string> &words, int left, int right, string sep) {
        string s = words[left];
        for (int i = left + 1; i < right; ++i) {
            s += sep + words[i];
        }
        return s;
    }

public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> ans;
        int right = 0, n = words.size();
        while(true) {
            int left = right;
            int sumLen = 0;
            while(right < n && sumLen + words[right].size() + right - left <= maxWidth) {
                sumLen += words[right].size();
                right++;
            }
            if(right == n) {
                string s = join(words, left, n, " ");
                ans.emplace_back(s + blank(maxWidth - s.length()));
                return ans;
            }
            int numWords = right - left;
            int numSpaces = maxWidth - sumLen;
            if(numWords == 1) {
                ans.emplace_back(words[left] + blank(numSpaces));
                continue;
            }
            int avgSpace = numSpaces / (numWords - 1);
            int extraSpace = numSpaces % (numWords - 1);
            string s1 = join(words, left, left + extraSpace + 1, blank(avgSpace+1));
            string s2 = join(words, left + extraSpace + 1, right, blank(avgSpace));
            ans.emplace_back(s1 + blank(avgSpace) + s2);
        }
    }
};

#include <iostream>
#include <vector>

int main() {
    Solution solution;

    // 你可以根据需要修改输入数据
    vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth = 20;

    // 调用函数得到结果
    vector<string> result = solution.fullJustify(words, maxWidth);

    // 输出结果
    for (const string& line : result) {
        cout << "\"" << line << "\"" << endl;
    }
    return 0;
}
