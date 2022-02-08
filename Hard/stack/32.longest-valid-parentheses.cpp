#include<stack>

class Solution {
public:
    int longestValidParentheses(string s) {
     
int lRetVal = 0;
std::stack <int> VS1;
int lLength = s.length();
int i =0;

VS1.push(-1);

for( i =0 ; i < lLength ; i++)
{
	if(s[i] == '(')
		VS1.push(i);
	else
	{
		if(!VS1.empty())
			VS1.pop();

		if(!VS1.empty())
			lRetVal = max(lRetVal,i - VS1.top());
		else
			VS1.push(i);
	}
}
return lRetVal;

    }
};