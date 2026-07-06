class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1]; // descending end
                 return a[0] < b[0];
             });
        int output = 1;
        int maxEnd = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] > maxEnd) {
                output++;
                maxEnd = intervals[i][1];
            }
        }
        return output;
    }
};