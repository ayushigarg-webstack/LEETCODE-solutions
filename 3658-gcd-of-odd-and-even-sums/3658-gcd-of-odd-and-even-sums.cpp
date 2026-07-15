class Solution {
public:
    int gcdOfOddEvenSums(int n) {
    return __gcd((n*(n+1)), (n*n));
    }
};