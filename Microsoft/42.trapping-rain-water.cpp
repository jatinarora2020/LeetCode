class Solution {
public:
    int trap(vector<int>& height) {
        
        int low = 0;
        int high = height.size() - 1;
        int lLeftMax = 0;
        int lRightMax = 0;
        int lResult = 0;
        
        while(low <= high)
        {
            if(height[low] < height[high])
            {
                if(lLeftMax < height[low])
                    lLeftMax = height[low];
                else
                    lResult += lLeftMax - height[low];
                low++;
            }
            else
            {
                if(lRightMax < height[high])
                    lRightMax = height[high];
                else
                    lResult += lRightMax - height[high];
                high--;
            }
        }
        
        return lResult;
            
    }
};