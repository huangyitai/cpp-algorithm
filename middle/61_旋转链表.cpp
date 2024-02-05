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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        int len = 0;
        ListNode *p = head;
        ListNode *tail = head;
        // 遍历一遍得到链表的长度和链表尾指针
        while(p) {
            len++;
            p = p->next;
            if(p) tail = p;
        }   
        // 最后的 % len 是有意义的
        // 比如说 样例为 list:[1] k=1 的情况
        k = (len - k % len) % len;
        if(k==0) return head;
        p = head;
        int cnt = 1;
        while(cnt < k && p) {
            cnt ++;
            p = p->next;
        }
        ListNode *ans = p->next;
        tail->next = head;
        p->next = NULL;
        return ans;
    }
};