class Solution {
public:
    vector<int> next_smaller_element_index(vector<int> arr, int n) 
    {
        vector<int> indexes(n);
        stack<pair<int,int>> s;
        s.push({-1, n});
        
        for(int i = n-1; i>=0; i--)     //traversing from right to left
        {
            int current = arr[i];
            
            while( s.top().first >= current )
            {                           
                s.pop();       
            }
            
            indexes[i] = s.top().second;
            
            s.push({arr[i], i});
        }
        
        return indexes;
    } 
    vector<int> prev_smaller_element_index(vector<int> arr, int n)
    {
        vector<int> indexes(n);
        stack<pair<int,int>> s;
        s.push({-1, -1});
        
        for(int i=0; i<n; i++)     //traversing from left to right
        {
            int current = arr[i];
            
            while( s.top().first >= current ) 
            {               
                s.pop();    
            }
            
            indexes[i] = s.top().second;
            
            s.push({arr[i], i});  
        }
        
        return indexes;
    }
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> next = next_smaller_element_index(heights, n);
        vector<int> prev = prev_smaller_element_index(heights, n);

        int max_area = INT_MIN;

        for(int i=0; i<n; i++)
        {
            max_area = max(max_area, heights[i] * (next[i] - prev[i] - 1));
        }

        return max_area;    
    }
};
