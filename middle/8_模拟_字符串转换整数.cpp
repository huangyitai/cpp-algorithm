#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int st = 0, sign = 1;
        long long ans = 0;
        int len = s.size();
        while(s[st]==' ') {
            st++;
        }
        if(s[st] == '+' || s[st] == '-') {
            sign = s[st++] == '+' ? 1 : -1;
        }
        while(s[st]=='0') {
            st++;
        }
        for(int i=st; i<len; i++) {
            if(!(s[i]>='0' && s[i]<='9')) {
                break;
            }
            ans = (s[i]-'0') + ans * 10;
            if(ans * sign >= INT_MAX || ans * sign <= INT_MIN) {
                return sign == 1 ? INT_MAX: INT_MIN;
            } 
        }
        return ans * sign;
    }
};

int main() {
    string s = "-91283472332";
    Solution solution;
    cout<< solution.myAtoi(s) <<endl;
    return 0;
}