class Solution {
public:
    string originalDigits(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        map<char,int> m;
        int n = s.size();
        string ans = "";
        map<int,char> temp;
    
        for(int i=0; i<n; i++)
        {
            m[s[i]]++;
        }

        vector<int> nums_total(10); //contains frequency of 0-9

        nums_total[0] = m['z'];
        m['e'] -= m['z'];
        m['r'] -= m['z'];
        m['o'] -= m['z'];
        m['z'] -= m['z'];

        nums_total[2] = m['w'];
        m['t'] -= m['w'];
        m['o'] -= m['w'];
        m['w'] -= m['w'];
    
        nums_total[4] = m['u'];
        m['f'] -= m['u'];
        m['o'] -= m['u'];
        m['r'] -= m['u']; 
        m['u'] -= m['u'];

        nums_total[6] = m['x'];
        m['s'] -= m['x'];
        m['i'] -= m['x'];
        m['x'] -= m['x'];

        nums_total[8] = m['g'];
        m['e'] -= m['g'];
        m['i'] -= m['g'];
        m['h'] -= m['g'];
        m['t'] -= m['g'];
        m['g'] -= m['g'];
    
        nums_total[3] = m['h'];    //now remaining h is for three
        m['t'] -= m['h'];
        m['r'] -= m['h'];
        m['e'] -= m['h'];
        m['e'] -= m['h'];
        m['h'] -= m['h'];
     
        nums_total[5] = m['f'];     //now remaining f is for five
        m['i'] -= m['f'];
        m['v'] -= m['f'];
        m['e'] -= m['f'];
        m['f'] -= m['f'];

        nums_total[9] = m['i'];
        m['n'] -= m['i'];
        m['n'] -= m['i'];
        m['e'] -= m['i'];
        m['i'] -= m['i'];

        nums_total[1] = m['o'];
        m['n'] -= m['o'];
        m['e'] -= m['o'];
        m['o'] -= m['o'];

        nums_total[7] = m['v'];
        m['s'] -= m['v'];
        m['e'] -= m['v'];
        m['n'] -= m['v'];
        m['v'] -= m['v'];

        temp[0] = '0';
        temp[1] = '1';
        temp[2] = '2';
        temp[3] = '3';
        temp[4] = '4';
        temp[5] = '5';
        temp[6] = '6';
        temp[7] = '7';
        temp[8] = '8';
        temp[9] = '9';

        for(int i=0; i<=9; i++)
        {
            for(int j=0; j<nums_total[i]; j++)
            {
                ans += temp[i];
            }
        }

        return ans;
    }
};
