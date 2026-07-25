class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0;
        int max2 = 0;
        int N=n;
        int i=0;
        int j=0;
        int iOfMax;
        while(N>0)
        {
            int x = N%10;
            if(x>max1)
            {
                max1 = x;
                iOfMax = i;
            }
            N = N/10;
            i++;
        }
        N=n;
        while(N>0)
        {
            int x = N%10;
            if(x>max2 && j!=iOfMax)
            {
                max2 = x;
            }
            N = N/10;
            j++;
        }
        return max1*max2;
    }
};