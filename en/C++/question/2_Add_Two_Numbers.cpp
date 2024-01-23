// @algorithm @lc id=2 lang=cpp 
// @title add-two-numbers


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([2,4,3],[5,6,4])=[7,0,8]
// @test([0],[0])=[0]
// @test([9,9,9,9,9,9,9],[9,9,9,9])=[8,9,9,9,0,0,0,1]
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if( l1 == nullptr && l2 == nullptr ) {
            return nullptr;
        }
        int flag = 0;
        ListNode *ret,*node;
        while(1) {
            if( l1 == nullptr && l2 == nullptr && flag == 0) {
                break;
            }
            int v1 = (l1 == nullptr ? 0 : l1->val);
            int v2 = (l2 == nullptr ? 0 : l2->val);
            int v = v1 + v2 + flag;
            flag = v / 10;
            v %= 10;
            if( ret == nullptr ) {
                ret = new ListNode(0);
                node = ret;
                node->val = v;
                continue;
            }
            node->next = new ListNode(v);
            node = node->next;
            if( l1 != nullptr ) {
                l1 = l1->next;
            }
            if( l2 != nullptr ) {
                l2 = l2->next;
            }

        }
        return ret;
    }
};