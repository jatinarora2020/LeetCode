using namespace std;

#include "iostream"
#include "vector"
#include "string"
#include "stack"

class Solution {
public:
    
    string lRetVal;
    int visited[26] = {-1}; //-1 doesn't exist, 0 not visited ,1 first node,2 means visited
    bool Dag[26][26] = {false};
    stack<int> lTpSrtStk;
    
    bool mIsCyclic(int idx)
    {
        bool lRetVal = true;
        if(visited[idx] == 2)
            return false;
        visited[idx] = 2;
        for(int i = 0; i < 26;i++)
        {
            if(idx == i || visited[i] == -1) continue;
            if(Dag[idx][i])
                lRetVal = mIsCyclic(i);
            if(!lRetVal)
                break;
        }
        visited[idx] = 0;
        return lRetVal;
    }
    
    void mGetTopologicalSort(int idx)
    {
        visited[idx] = 2;
        for(int i = 0; i < 26; i++)
        {
            if(idx == i || visited[i] == -1) continue;
            if(Dag[idx][i] && (visited[i] == 0))
                mGetTopologicalSort(i);
        }
        
        lTpSrtStk.push(idx);
    }
    
    string alienOrder(vector<string>& words) {
        
        int i = 0,k = 0,j = 0,lLen1 = 0, lLen2 = 0,lNotAllowed = 0; 
        int lSize = words.size();
        bool lValid  = false;
        
        for(i = 0 ; i < 26 ; i++)
            visited[i] = -1;
        
        if(lSize == 1)
        {
            string s1;
            s1 = words[0];
            lLen1 = s1.length();
            k = 0;
            while(k < lLen1)
                {
                     if(visited[s1[k] - 'a'] == -1)
                        visited[s1[k] -'a'] = 1;
                      k++;
                }
        }
        
        for(i =0; i <lSize - 1 ;i++)
        {
             string s1,s2;
            s1 = words[i];
            visited[s1[0] - 'a'] = 0;
            for(j = i+1 ; j < lSize;j++)
            {
                s2 = words[j];
                if(s1[0] != s2[0])
                {
                    Dag[s1[0] - 'a'][s2[0] - 'a'] = true; //Edge from vertex to another vertex
                    visited[s2[0] - 'a'] = 0;
                }
            }
        }
         
        for(i = 0; i < lSize - 1 ; i++)
        {
            string s1,s2;
            s1 = words[i];
            s2 = words[i+1];
            lLen1 = s1.length();
            lLen2 = s2.length();
            k = 0; j = 0;
            while(k < lLen1 && j < lLen2)
            {
                if(s1[k] == s2[j])
                {
                     visited[s1[k] - 'a'] = 0;
                     k++;
                     j++;
                }
                else
                {
                    visited[s1[k] -'a'] = 0;
                    visited[s2[k] - 'a'] = 0;
                    Dag[s1[k] - 'a'][s2[k] - 'a'] = true; //Edge from vertex to another vertex
                    break;
                }
            }
            
            if(j == lLen2 && k < lLen1) lNotAllowed = 1;
            if(j < lLen2)
            {
                while(j < lLen2)
                {
                    
                      visited[s2[j] -'a'] = 0;
                      j++;
                }
            }
             if(k < lLen1)
            {
                while(k < lLen1)
                {
                        visited[s1[k] -'a'] = 0;
                      k++;
                }
            }
        }
        
        if(lNotAllowed)
            return lRetVal;
        
        for(i =0 ;i < 26 ;i++)
        {
          if(visited[i]  == 0)
           {
            lValid = mIsCyclic(i);  //Detect whether graph is cyclic or not
            if(!lValid)
                break;
           }
        }
        
        if(!lValid)
            return lRetVal;
        
        for(i = 0; i < 26; i++)
        {
            if(!visited[i])
                mGetTopologicalSort(i);
        }
        
        while(!lTpSrtStk.empty())
        {
            char c = lTpSrtStk.top() + 'a';
            lRetVal += c;
            lTpSrtStk.pop();
        }
        
        return lRetVal;
    }
};


int main()
{
    Solution s;
    vector<string> tc = {"ze","yf","xd","wd","vd","ua","tt","sz","rd","qd","pz","op","nw","mt","ln","ko","jm","il","ho","gk","fa","ed","dg","ct","bb","ba"}; //TLE TC
    cout<< "output " << s.alienOrder(tc) <<endl;
    return 0;

}