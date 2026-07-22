class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int startColor = image[sr][sc];
        image[sr][sc] = color;
        if (startColor == color)
            return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int row = nrow + drow[i];
                int col = ncol + dcol[i];
                if (row >= 0 && row < n && col >= 0 && col < m) {
                    if (image[row][col] == startColor) {
                        image[row][col]=color;
                        q.push({row, col});
                    }
                }
            }
        }
        return image;
    }
};