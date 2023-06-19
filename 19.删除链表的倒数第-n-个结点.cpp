/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( n < 1 || !head ) return nullptr;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast && n-- > 0)
        {
            fast=fast->next;
        }
        if(!fast)
        {
            head = head->next;
            return head;
        }

        while(fast->next && slow->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode * rm = slow->next;
        slow->next = rm->next;
        rm->next = nullptr;
        return head;
    }
};
// @lc code=end

