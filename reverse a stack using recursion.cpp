class Solution{
public:

    void insertAtPosition(stack<int> &s, int &x, int &i)
    {
        if( s.size() == i )     // when s.size() == 0
        {
            s.push(x);
            return;
        }
        
        int temp = s.top();
        
        s.pop();
        
        insertAtPosition(s, x, i) ;
        
        s.push(temp);
    }
    
    void Reverse(stack<int> &St)
    {
        if( St.empty() )
        return;
        
        int n = St.size();
        for(int i=0; i<n; i++)
        {
            int top_element = St.top();
            
            St.pop();
            
            insertAtPosition(St, top_element, i);
        }
    }
};
