#include<iostream>
#include<string>
#include<vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        int up = 0;
        ListNode* head = new ListNode();
        ListNode* ptr = head;
        
        while(l1 && l2) {
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = (l1->val + l2->val + up) % 10;
            up = (l1->val + l2->val + up) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = (l1->val + up) % 10;
            up = (l1->val + up) / 10;
            l1 = l1->next;
        }
        while(l2) {
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = (l2->val + up) % 10;
            up = (l2->val + up) / 10;
            l2 = l2->next;
        }
        if(up != 0) {
            ptr->next = new ListNode(up);
        }
        return head->next;
    }
};

// 输出链表
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // 构造测试链表
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);

    // 输出原始链表
    cout << "Original Lists:" << endl;
    cout << "l1: ";
    printList(l1);
    cout << "l2: ";
    printList(l2);

    // 调用相加函数
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // 输出相加结果
    cout << "Result: ";
    printList(result);

    return 0;
}