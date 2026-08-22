class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum = 0;
        int product = 1;
        while(n>0) {
            int x = n%10;
            sum = sum + x;
            product = product * x;
            n = n/10;
        }
        int ans = sum+product;
        if(num%ans==0) return true;
        else return false;
    }
};