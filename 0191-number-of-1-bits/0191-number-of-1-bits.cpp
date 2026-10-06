class Solution {
public:
    int hammingWeight(int n) {
        int x = n;
        int count=0;
        while(x>0) {
            int rem = x%2;
            x=x/2;
            if(rem==1) count++;
        }
        return count;
    }
};