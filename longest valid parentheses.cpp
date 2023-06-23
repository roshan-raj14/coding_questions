// leetcode 32 - longest valid parentheses

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n = s.size();
        stack<int> stk;     // to store indexes of '(' to get the length
        stk.push(-1);
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
            stk.push(i);

            else
            {
                stk.pop();
                if( stk.empty() )
                {
                    stk.push(i);
                }
                else
                {
                    int len = i - stk.top();
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};
