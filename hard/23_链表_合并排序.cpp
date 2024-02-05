#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    struct node {
        int val;
        ListNode *ptr;
        bool operator < (node op) const {
            // 从大到小
            return val > op.val;
        }
    };

    priority_queue <node> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i=0; i<lists.size(); i++) {
            if (lists[i]) q.push({lists[i]->val, lists[i]});
        }
        ListNode *head = new ListNode(), *curr = head;
        while(!q.empty()) {
            node tmp = q.top(); q.pop();
            curr->next = new ListNode(tmp.val);
            curr = curr -> next;
            if(tmp.ptr->next) q.push({tmp.ptr->next->val, tmp.ptr->next});
        }
        return head->next;
    }
};


int main() {
    // 创建几个有序链表
    ListNode* list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* list3 = new ListNode(2, new ListNode(6));

    // 构建一个 vector 存储这些链表
    vector<ListNode*> lists = {list1, list2, list3};

    // 创建 Solution 对象
    Solution solution;

    // 调用 mergeKLists 函数
    ListNode* mergedList = solution.mergeKLists(lists);

    // 打印合并后的链表
    while (mergedList != nullptr) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }

    // 释放内存
    // 这里省略了释放链表节点的代码，实际应该在合适的地方释放内存

    return 0;
}