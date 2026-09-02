class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int litterCount = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        // Find S and assign IDs to L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        if (litterCount == 0)
            return 0;

        int totalMasks = 1 << litterCount;
        int allMask = totalMasks - 1;

        /*
            best[r][c][mask] =
            maximum energy with which we have reached
            (r, c) after collecting 'mask' litter.
        */

        vector<int> best(m * n * totalMasks, -1);

        auto index = [&](int r, int c, int mask) {
            return ((r * n + c) * totalMasks + mask);
        };

        // BFS state:
        // {row, col, remaining energy, mask}
        queue<array<int, 4>> q;

        q.push({sr, sc, energy, 0});

        best[index(sr, sc, 0)] = energy;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == allMask)
                    return moves;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Cannot make a move without energy
                    if (e == 0)
                        continue;

                    int newEnergy = e - 1;
                    int newMask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int bit = id[nr][nc];
                        newMask |= (1 << bit);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    int idx = index(nr, nc, newMask);

                    /*
                        Dominance optimization:

                        If we have already reached the same
                        position with the same mask and MORE
                        energy, this state can be ignored.
                    */
                    if (best[idx] >= newEnergy)
                        continue;

                    best[idx] = newEnergy;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};