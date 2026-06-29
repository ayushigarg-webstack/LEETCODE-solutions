class Solution {
public:
    double myPow(double x, int n) {
        /*if(x == 0) return 0;
        if(x == 1) return 1;
        double pow = 1;
        if(n>=0)
        { 
            for(int i = 0; i < n; i++)
            {
                pow = pow*x;
            }
        }
        else
        {
            x = 1/x;
            n = n*(-1);
            for(int i = 0; i < n; i++)
            {
                pow = pow*x;
            }
        }    
        return pow;*/

        long long N = n;
        if(N<0)
        {
            x = 1/x;
            N = -N;
        }
        double ans = 1;
        while(N>0)
        {
            if(N%2==1)
            {
                ans*=x;
            }
            x*=x;
            N/=2;
        }
        return ans;
    }
};