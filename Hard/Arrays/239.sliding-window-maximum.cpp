
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> lDeque;
        deque<int>::iterator itr;
        int i = 0;
        int lLeft = 0;
        vector<int> lResult;
        
        lDeque.push_back(i);
        for(i = 1; i < k ; i++)
        {
            while(!lDeque.empty() && nums[i] > nums[lDeque.back()])
                lDeque.pop_back();
            lDeque.push_back(i);
        }
        
        lResult.push_back(nums[lDeque.front()]);
        
        for(i = k; i < nums.size(); i++)
        {
            if(!lDeque.empty() && nums[lDeque.front()] == nums[lLeft])
                lDeque.pop_front();
            lLeft++;
             while(!lDeque.empty() && nums[i] > nums[lDeque.back()])
                lDeque.pop_back();
            lDeque.push_back(i);
            lResult.push_back(nums[lDeque.front()]);
        }
        
        return lResult;
    }
};