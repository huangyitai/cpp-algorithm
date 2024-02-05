#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>& arr, int k, int l, int r) {
        if(l >= r) return;
        if(r < k || l > k) return;
        int i = l, j = r;
        int flagVal = arr[l];
        while(i < j) {
            while(arr[j] > flagVal && i < j) 
                j--;
            while(arr[i] < flagVal && i < j)
                i++;
            int tmp = arr[i];
            arr[i] = arr[j], arr[j] = tmp;
        }
        swap(arr[l], arr[i]);
        quickSort(arr, k, l, i-1);
        quickSort(arr, k, i+1, r);
    }

    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        quickSort(stock, cnt-1, 0, stock.size()-1);
        vector<int> ans;
        for(int i=0; i<cnt; i++) {
            ans.push_back(stock[i]);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // 测试用例
    std::vector<int> arr = {0,0,1,2,4,2,2,3,1,4};
    int k = 8;

    // 调用函数
    std::vector<int> result = solution.inventoryManagement(arr, k);

    // 输出结果
    std::cout << "Least " << k << " numbers: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
