#include <vector>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int vis[10];
    vector<int> ansItem;
    // ansItem作为参数会有内存访问的问题，但是我还没有排查出是什么问题
    // 将ansItem移动到public作为类的全局变量就没有问题
    // void dfs(vector<int>& nums, vector<int>& ansItem, int cnt) {

    void dfs(vector<int>& nums, int cnt) {
        int len = nums.size();
        if(cnt == len) {
            ans.push_back(ansItem);
            return ;
        }
        for(int i=0; i<len; i++) {
            if(!vis[i]) {
                ansItem.push_back(nums[i]);
                vis[i] = true;
                dfs(nums, cnt+1);
                vis[i] = false;
                ansItem.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        memset(vis, 0, sizeof(vis));
        ansItem.clear();
        // 同上，ansItem 局部变量作为参数会有内存访问的错误
        // vector<int> ansItem;
        dfs(nums, 0);
        return ans;
    }
};


int main() {
    Solution solution;

    // 测试用例
    std::vector<int> nums = {1, 2, 3};

    // 调用排列函数
    std::vector<std::vector<int>> result = solution.permute(nums);

    // 打印结果
    std::cout << "Permutations:" << std::endl;
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout<<result[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<string(4, '*')<<endl;
    return 0;
}
/*
    [1,2,3]
    root(permute) 
     |
    /|\
   1 2 3
  /|
 2 3
 | |
 3 2
*/
 