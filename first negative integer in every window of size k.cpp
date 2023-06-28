// gfg - first negative integer in every window of size k
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, 
long long int K)
{
    vector<long long int> ans;
    queue<long long int> q;
    // create the first window
    for(long long int i=0; i<K; i++)
    {
        if(A[i] < 0)  // first window me jitne bhi negative elements hai unke index strore krliye
        {
            q.push(i);
        }
    }
    
    // now slide throughout the array with windows
    for(long long int i=K; i<N; i++)
    {
        // first strore the answer of previous window
        if( !q.empty() )
        {
            ans.push_back( A[q.front()] );
        }
        else
        {
            ans.push_back( 0 );
        }
        
        // ab new window banana hai, so out of bounds wale elements ko remove karo
        while( (q.size() > 0) && q.front() < i-(K-1) )
        {
            q.pop();
        }
        
        // ab new window me current element ko insert krna hai
        if( A[i] < 0 )
        {
            q.push(i);
        }
    }
    
    if( !q.empty() )    // last wale window ka ans store karo
    {
        ans.push_back( A[q.front()] );
    }
    else
    {
        ans.push_back( 0 );
    }
        
    return ans;
}
