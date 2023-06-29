// gfg- first non repeating character in a stream

string FirstNonRepeating(string s)
		{
		    // Code here
		    vector<int> freq(26,0);
		    queue<char> q;
		    string ans;
		    int n = s.size();
		    
		    for(int i=0; i<n; i++)
		    {
		        freq[s[i] - 'a']++;
		        
		        q.push(s[i]);
		        
		        while(q.size() > 0 && freq[q.front() - 'a'] > 1)
		        {
		            q.pop();
		        }
		        
		        if(q.size() == 0)
		        {
		            ans.push_back('#');
		        }
		        else
		        {
		            ans.push_back(q.front());
		        }
		    }
		    return ans;
		}
