class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int lMaxResult = 0;
        int lCurResult = 0;
        int lTopIdx  = -1;
        int lSize = heights.size();
        int i = 0;
        s.push(-1);
        for(i = 0; i < lSize; i++)
        {
            while(s.top() >=0 && heights[s.top()] > heights[i])
             {
               lTopIdx = s.top();
               lCurResult = 0;
               s.pop();
               lCurResult = (i - s.top() - 1) * heights[lTopIdx];
               if(lCurResult > lMaxResult)
                  lMaxResult = lCurResult;
                }
            s.push(i);
        }
        
        while(s.top() != -1)
        {
            lTopIdx = s.top();
            lCurResult = 0;
            s.pop();
            lCurResult = (i - s.top() - 1) * heights[lTopIdx];
            if(lCurResult > lMaxResult)
                lMaxResult = lCurResult;
        }
        
        return lMaxResult;
    }
};