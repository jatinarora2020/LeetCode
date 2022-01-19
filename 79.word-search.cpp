using namespace std;
#include "iostream"
#include "string"
#include "vector"

class Solution
{
public:
    bool visited[6][6] = {false};
    bool word_exist(int m, int n, int i, int j, int k, vector<vector<char>> &board, string word);
    bool exist(vector<vector<char>> &board, string word)
    {

        bool lRetVal = false;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
              lRetVal = word_exist(m, n, i, j, 0, board, word);
              if(lRetVal) return lRetVal;
            }
        }
        return lRetVal;
    }
};

bool Solution::word_exist(int m, int n, int i, int j, int k, vector<vector<char>> &board, string word)
{
    bool lRetVal = false;
  
    int lArri[] = {1,-1,0,0};
    int lArrj[] = {0,0,1,-1};
  
    if (i == m || j == n || i < 0 || j < 0 || visited[i][j] == true)
        return false;
    
    visited[i][j] = true;

    if (word[k] != board[i][j])
    {
      visited[i][j] = false;
      return false;
    }
    else
    {
        if (k == word.length() -1 )
        {
           visited[i][j] = false;
           return true;
        }
           
    }
    

    for(int l = 0 ; l < 4 ;l++)
    {
        {
            lRetVal = word_exist(m, n, i + lArri[l], j + lArrj[l], k + 1, board, word);
            if (lRetVal)
            {
              visited[i][j] = false;
              return lRetVal;
            } 
        }
    }
    visited[i][j] = false;
    return lRetVal;
}
// @lc code=end

int main()
{
    return 0;
}
