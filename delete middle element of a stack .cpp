class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        if( sizeOfStack % 2 == 1)       // base case
        {
            if( s.size() == (sizeOfStack/2 + 1) )
            {
                s.pop();
                return;
            }
        }
        
        if( sizeOfStack % 2 == 0)       // base case
        {
            if( s.size() == sizeOfStack/2 )
            {
                s.pop();
                return;
            }
        }
        
        int temp = s.top();     // storing the current top value
        
        s.pop();                // popping it for recursion call
        
        deleteMid(s, sizeOfStack);
        
        s.push(temp);           // backtracking
    }
};
