#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size();
        vector<string> v;
        v.push_back("/");
        for(int i=0; i<len; i++){
            if(path[i] == '/') {
                if(path.find("/", i+1) != EOF) {
                    int nextSlash = path.find("/", i+1);
                    string s = path.substr(i+1, nextSlash - i - 1);
                    v.push_back(s);
                }else {
                    string s = path.substr(i+1, len-i);  
                    v.push_back(s);
                }
            } 
        }
        vector<string>::iterator it = v.begin();
        for(it = v.begin(); it!=v.end(); ) {
            if(*it==".") {
                it = v.erase(it);
            } else if(*it=="..") {
                it = v.erase(it);
                if(it-1 == v.begin()) {
                    continue;
                } else {
                    it = v.erase(it-1);
                }
            } else if(*it=="") {
                it = v.erase(it);
            } else{
                it ++;
            }
        }
        string ans = "/";
        for(it = v.begin()+1; it!=v.end(); it++ ) {
            ans += *it;
            if(it+1 != v.end()) {
                ans += "/";
            }
        }
        return ans;
    }
};

int main() {
    Solution *s = new(Solution);
    string str = "/a/./b/../../c/";
    cout<<s->simplifyPath(str)<<endl;
}