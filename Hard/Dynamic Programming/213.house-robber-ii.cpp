/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
#include "iostream"
#include "vector"
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int lSize = nums.size();
        vector<int> lDP[lSize];

        lDp[lSize - 1] = nums[lSize - 1];
        lDp[lSize -2] = nums[lSize - 2];
        for(int i = nums.size()- 3 ;i >= 0; i--)
        {
            
        }
    }
};
// @lc code=end

