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
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode *curr = head;
        // 关键是: newHead / A->newHead 
        ListNode *newHead = tail->next; 
        ListNode *next;
        ListNode *end = tail->next;
        while(curr != end) {
            // 节点的结构是: curr -> next -> nextnext;
            next = curr->next;
            curr->next = newHead;
            newHead = curr;
            curr = next;
        }
        return pair<ListNode*, ListNode*>(newHead, head);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ans = new ListNode();
        ListNode *pre = ans;
        pre->next = head;
        pair<ListNode*, ListNode*> p;
        int cnt = 0;
        while(head) {
            // pre -> head -> ... -> tail
            // pre -> tail -> ... -> head
            if(++cnt == k) {
                p = myReverse(pre->next, head);
                cnt = 0;
                pre->next = p.first;
                pre = p.second;
                head = p.second->next;
                continue;
            }
            head = head->next;
        }
        return ans->next;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2); 
    head->next->next = new ListNode(3); 
    head->next->next->next = new ListNode(4);
    Solution solution;
    pair<ListNode*, ListNode*> p =  solution.myReverse(head, head->next->next->next); 
    ListNode *tmp = p.first;
    while(tmp) {
        cout<<tmp->val<<' ';
        tmp = tmp->next;
    }
    cout<<endl;

    tmp = solution.reverseKGroup(p.first, 2); 
    while(tmp) {
        cout<<tmp->val<<' ';
        tmp = tmp->next;
    }
    return 0;
}