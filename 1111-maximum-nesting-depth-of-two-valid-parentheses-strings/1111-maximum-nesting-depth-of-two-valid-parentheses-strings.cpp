class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int depth = 0;

        for (char ch : seq) {
            if (ch == '(') {
                // Use current depth to decide the group
                ans.push_back(depth % 2);
                depth++;
            } 
            else {
                depth--;
                // Matching '(' was at this depth
                ans.push_back(depth % 2);
            }
        }

        return ans;
    }
};