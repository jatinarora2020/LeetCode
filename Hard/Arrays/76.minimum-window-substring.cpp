using namespace std;

#include "iostream"
#include "unordered_map"
#include "string"
class Solution {
public:
    string minWindow(string s, string t) {
        
        int lLeft = 0, lRight = 0,i = 0;
        unordered_map<char,int> lTextMap;
        unordered_map<char,int> lCurWinMap;
        unordered_map<char, int>::iterator itr;
        unordered_map<char, int>::iterator itr2;
        int found = 0;
        int lTlength = t.length();
        int lSLength = s.length();
        int lStart = -1;
        int lEnd = -1;
        
        for(i = 0; i < lTlength; i++)
        {
            itr = lTextMap.find(t[i]);
            if(itr == lTextMap.end())
                lTextMap.insert(make_pair(t[i],1));
            else
                itr->second += 1;
        }
        
        while(lRight < lSLength)
        {
            itr = lCurWinMap.find(s[lRight]);
            if(itr == lCurWinMap.end())
                lCurWinMap.insert(make_pair(s[lRight],1));
            else
                itr->second += 1;
            itr2 = lTextMap.find(s[lRight]);
            itr = lCurWinMap.find(s[lRight]);
            if(itr2 != lTextMap.end())
            {
                if(itr2->second >= itr->second)
                    found++;

            }

            lRight++;
            
            
                while(left <= right && found == lTlength)
                {
                     if((lStart < 0 && lEnd < 0) || ((lEnd - lStart) > (lRight - lLeft)))
                   {
                       lStart = lLeft;
                       lEnd = lRight;
                   }
                
                itr = lCurWinMap.find(s[lLeft]);
                if(itr != lCurWinMap.end())
                   itr->second -= 1;
                itr2 = lTextMap.find(s[lLeft]);
                if(itr2 != lTextMap.end())
                {
                    if(itr->second < itr2->second)
                        found--;
                }
                lLeft++;
                } 
        }
    
    string lRetVal;
        int j = 0;
    for(i = lStart; i < lEnd;  i++)
        lRetVal+= s[i];            
    return lRetVal;
}
    
};

int main()
{
    Solution S;
    cout<< S.minWindow("AA","AA");
}