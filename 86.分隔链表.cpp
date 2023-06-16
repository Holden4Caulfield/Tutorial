/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less = new ListNode();
        ListNode *bigger = new ListNode();
        ListNode * tmp = head, * less_head = less,*bigger_head = bigger;
        while( tmp)
        {
            if(tmp->val < x)
            {
                less->next = tmp;
                less = less->next;
            }
            else
            {
                bigger->next = tmp;
                bigger=bigger->next;
            }
            ListNode * next_node = tmp->next;
            tmp->next = nullptr;
            tmp=next_node;
        }
        less->next = bigger_head->next;
        return less_head->next;
    }
};
// @lc code=end

