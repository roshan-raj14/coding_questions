class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
    vector<int>& capital)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = profits.size();
        map<int,vector<int>> m;

        if(k >= n)
        {
            vector<pair<int,int>> v;
            for(int i=0; i<n; i++)
            {
                v.push_back({capital[i], profits[i]});
            }
            sort(v.begin(), v.end());

            for(int i=0; i<n; i++)
            {
                if(v[i].first <= w)
                {
                    w += v[i].second;
                }
                else
                break;
            }

            return w;
        }

        for(int i=0; i<n; i++)
        {
            m[profits[i]].push_back(capital[i]);
        }  

        for(int i=0; i<n; i++)
        {
            sort(m[profits[i]].begin(), m[profits[i]].end());
        }

        int count = 0;
        
        for(int i=0; i<n; i++)
        {
            if(count == k)
            break;

            int curr_profit = 0;
            for(auto it : m)
            {
                if(it.second.size() > 0 && it.second[0] <= w)
                curr_profit = it.first;
            }

            if(m[curr_profit].size() > 0)
            m[curr_profit].erase( m[curr_profit].begin() );

            if(curr_profit == 0)
            break;

            w += curr_profit;
            count++;
        }

        return w;
    }
};
