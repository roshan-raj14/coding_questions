// leetcode 239 - sliding window maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> ans;
        deque<int> q;   //using deque bcz popback and popfront dono ka need hai
        int n = nums.size();

        // create the first window  (queue descending order me ban rha hai)
        for(int i=0; i<k; i++)
        {   //remove elements from the queue which are smaller than the curr element
            while( !q.empty() && nums[q.back()] <= nums[i] )
            {
                q.pop_back();
            }
            //ab sare chote elements ko hatane ke baad curr element index push karo
            q.push_back(i);
        }

        //now store the answer for the first window
        ans.push_back( nums[q.front()] );

        //now processing the remaining windows
        for(int i=k; i<n; i++)
        {
            //removing the elements from the front which are out of the new window
            while( !q.empty() && q.front() < i-(k-1) )
            {
                q.pop_front();
            }

            //now add the current element accordingly
            while( !q.empty() && nums[q.back()] <= nums[i] )
            {
                q.pop_back();
            }
            q.push_back(i);

            //and finally store the answer of the current window
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
