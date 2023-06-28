// gfg - reverse first k elements of a queue
queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    stack<int> stk;
    int n = q.size();
    int c = 0;
    
    while(c < k)
    {
        stk.push( q.front() );
        q.pop();
        c++;
    }
    
    while( !stk.empty() )
    {
        q.push( stk.top() );
        stk.pop();
    }
    
    for(int i = n-k; i > 0; i--)
    {
        q.push( q.front() );
        q.pop();
    }
    
    return q;
}
