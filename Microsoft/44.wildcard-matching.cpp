class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n+1][m+1];
        
        dp[0][0] = true;
        
        for(int j=1; j<m+1; j++){
            if(p[j-1] == '?')
                dp[0][j] = false;
            else if(p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
            else
                dp[0][j] = false;
        }
        
        for(int i=1; i<n+1; i++)
            dp[i][0] = false;

        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i][j-1] | dp[i-1][j]| dp[i-1][j-1];
                else
                    dp[i][j] = false;
            }
        }
        
        return dp[n][m];
    }
};