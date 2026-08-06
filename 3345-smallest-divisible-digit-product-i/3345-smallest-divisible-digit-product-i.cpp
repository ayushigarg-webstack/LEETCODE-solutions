class Solution {
public:
    bool isDivisible(int i, int t)
    {
        int product=1;
        while(i>0)
        {
            int x = i%10;
            product = product*x;
            i=i/10;
        }
        if(product%t==0) return true;
        else return false;
    }
    int smallestNumber(int n, int t) {
        int i = n;
        while(true)
        {
            if(isDivisible(i,t))
            {
                return i;
            }
            i++;
        }
    }
};