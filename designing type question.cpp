// leetcode 384 - shuffle an array, designing class type of ques

class Solution 
{
public:

    vector<int> vec;    //data members
    int n;

    Solution(vector<int>& nums)     //constructor
    {
        this->vec = nums;
        this->n = nums.size();
    }
    
    vector<int> reset()         //member functions
    {
        return vec;
    }
    
    vector<int> shuffle()
    {
        vector<int> temp = vec;

        for(int i=0; i<n; i++)
        {
            int j = rand() % n;     // returns a random int from 0 - n
            swap(temp[i], temp[j]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
