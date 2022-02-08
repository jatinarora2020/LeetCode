
#include "vector"
#include "iostream"
#include "queue"
#include "set"
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<vector<int>> lResult;
        vector<vector<int>> lWorkingSet;
     //   priority_queue<int> lMaxHeap; This doesn't have remove method
       multiset<int, greater<int>> lMaxHeapSet; //Greatest Element at the end
       multiset<int, greater<int> >::iterator itr;
        int i = 0,lMax = -1;
        
        /*Form the set from the given input */
        for(i = 0 ; i < buildings.size() ; i++)
        {
            vector<int> lXPoint,lYPoint;
            lXPoint.push_back(buildings[i][0]);
            lXPoint.push_back(buildings[i][2]);
            lYPoint.push_back(buildings[i][1]);
            lYPoint.push_back(-(buildings[i][2])); //End Point Mark by negative values
            lWorkingSet.push_back(lXPoint);
            lWorkingSet.push_back(lYPoint);
        }
        
        //Try Lamba as the sort mechanism please for god sake
        
         std::sort(std::begin(lWorkingSet),
              std::end(lWorkingSet), 
              [&](vector<int> a, vector<int> b) {
                  if(a[0] < b[0]) return true;
                  if(a[0] == b[0])
                  {
                      if(a[1] > b[1]) return true;
                  }
                  return false;
              });

        lMaxHeapSet.insert(0);

        for(i = 0 ; i < lWorkingSet.size();i++)
        {
          //  cout<<lWorkingSet[i][0]<<" "<<lWorkingSet[i][1]<<endl;

          if(lWorkingSet[i][1] > 0)
          {
              itr = lMaxHeapSet.begin();
              if(*itr < lWorkingSet[i][1])
                    lResult.push_back(lWorkingSet[i]);
              lMaxHeapSet.insert(lWorkingSet[i][1]);
          }
          else
          {
              lMaxHeapSet.erase(lMaxHeapSet.find(-(lWorkingSet[i][1])));
              itr = lMaxHeapSet.begin();
              if(*itr < lWorkingSet[i][1])
              {
                  vector<int> lIntrRes;
                  lIntrRes.push_back(lWorkingSet[i][0]);
                  lIntrRes.push_back(*itr);
                  lResult.push_back(lIntrRes);
              }
          }
        }

        return lResult;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> buildings = {{2,9,10},{2,9,11},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    s.getSkyline(buildings);
}