class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>merge;

        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            merge.push_back(intervals[i]);
            i++;
        }

        while(i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i++;
        }
        merge.push_back(newInterval);

        while(i < intervals.size())
        {
            merge.push_back(intervals[i]);
            i++;
        }

        return merge;
    }
};