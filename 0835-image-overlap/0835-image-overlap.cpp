class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {
        
        int n = img1.size();
        int ans = 0;

        // Try every possible translation
        for (int dx = -(n - 1); dx <= n - 1; dx++) {
            
            for (int dy = -(n - 1); dy <= n - 1; dy++) {
                
                int overlap = 0;

                // Check every cell of img1
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        
                        // We only care about 1s in img1
                        if (img1[i][j] == 0)
                            continue;

                        int ni = i + dx;
                        int nj = j + dy;

                        // Check if translated position is inside matrix
                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < n) {
                            
                            // Check overlap
                            if (img2[ni][nj] == 1) {
                                overlap++;
                            }
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};