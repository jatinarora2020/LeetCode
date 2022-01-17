/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
using namespace std;
#include "iostream"
#include "vector"

class Solution {
public:
    int rob(vector<int>& nums) {
        int lRetVal = 0;
        int lSize =  nums.size();
        int lMaxCostDp[lSize] = {0};
        lMaxCostDp[lSize - 1] = nums[lSize -1];
        lMaxCostDp[lSize - 2] = nums[lSize - 1] > nums[lSize -2] ? nums[lSize - 1] : nums[lSize - 2];
        lRetVal = lMaxCostDp[lSize - 1] > lMaxCostDp[lSize - 2] ? lMaxCostDp[lSize - 1] : lMaxCostDp[lSize - 2];
        for(int i = lSize - 3; i >= 0; i--)
        {
            lMaxCostDp[i] = lMaxCostDp[i+1] > (lMaxCostDp[i+2] +nums[i]) ? lMaxCostDp[i+1] : (lMaxCostDp[i+2] +nums[i]);
            if(lMaxCostDp[i] > lRetVal)
            lRetVal = lMaxCostDp[i];
        }
        return lRetVal;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums{2,7,9,3,1};
    cout<<s.rob(nums);
    return 0;

}

