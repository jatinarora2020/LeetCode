/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
#include "iostream"
#include "vector"
#include "set"
using namespace std;
// @lc code=start
/**
 * Definition for singly-linked list. */
  struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* lRetHeadList =  NULL;
        ListNode* lPrevNode = NULL;
        ListNode* lTempNode = NULL;
        auto my_compare = [](ListNode* l1, ListNode*  l2) {
                return l1->val > l2->val;
        };
    multiset<ListNode*,decltype(my_compare)> lMultiSetHeap(my_compare);
     multiset<ListNode*,decltype(my_compare)>::iterator itr;
    int i = 0 ;

    for(i = 0 ; i < lists.size();i++)
        lMultiSetHeap.insert(lists[i]);

    while(!lMultiSetHeap.empty())
    {
        itr = lMultiSetHeap.begin();
        lTempNode = *itr;
        if(lRetHeadList == NULL)
        {
            lRetHeadList = lTempNode;
            lPrevNode = lRetHeadList;
        }
        else
        {
            lPrevNode->next = lTempNode;
            lPrevNode = lPrevNode->next;
        }
        if(lTempNode->next)
          lMultiSetHeap.insert(lTempNode->next);
        lMultiSetHeap.erase(lMultiSetHeap.find(lTempNode));
    }
    
    return lRetHeadList;
}
};

int main()
{
    Solution s;
    return 0;
}

