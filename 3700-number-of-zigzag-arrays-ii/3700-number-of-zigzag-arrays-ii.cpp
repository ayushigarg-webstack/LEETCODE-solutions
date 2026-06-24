class Solution {
public:
    static const long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long aik = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    vector<long long> multiplyMatVec(const Matrix& A,
                                     const vector<long long>& v) {
        int n = A.size();

        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;

            for (int j = 0; j < n; j++) {
                if (A[i][j] == 0) continue;

                cur = (cur + A[i][j] * v[j]) % MOD;
            }

            res[i] = cur;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        vector<long long> init(S, 0);

        // length = 2 state
        for (int v = 1; v <= m; v++) {
            init[v - 1] = v - 1;         // up[v]
            init[m + v - 1] = m - v;     // down[v]
        }

        Matrix T(S, vector<long long>(S, 0));

        // up[v] <- sum down[u], u < v
        for (int v = 1; v <= m; v++) {
            for (int u = 1; u < v; u++) {
                T[v - 1][m + u - 1] = 1;
            }
        }

        // down[v] <- sum up[u], u > v
        for (int v = 1; v <= m; v++) {
            for (int u = v + 1; u <= m; u++) {
                T[m + v - 1][u - 1] = 1;
            }
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState = multiplyMatVec(P, init);

        long long ans = 0;
        for (long long x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};