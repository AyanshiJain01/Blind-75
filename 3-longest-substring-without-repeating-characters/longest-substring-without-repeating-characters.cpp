class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxLength = 0;
        int n = s.length();
        vector<int> index(128,-1); //ascii charcter 
        for(int r = 0; r < n; r++)
        {
            if(index[s[r]] >= l)
            {
                l = index[s[r]] + 1;
            }

            index[s[r]] = r;
            maxLength = max(maxLength, r-l+1);
        }
        return maxLength;
    }
};