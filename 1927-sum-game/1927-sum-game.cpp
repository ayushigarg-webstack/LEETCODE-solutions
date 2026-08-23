class Solution {
public:
    bool sumGame(string num) {
        int sum1 = 0, sum2 = 0;
        int noOfQ1 = 0, noOfQ2 = 0;
        for(int i = 0; i < num.size(); i++) {
            if(i<num.size()/2) {
                if(num[i]=='?') noOfQ1++;
                else sum1 += num[i]-'0';
            } else {
                if(num[i]=='?') noOfQ2++;
                else sum2 += num[i]-'0';
            }
        }
        if((noOfQ1+noOfQ2)%2==1) 
            return true;
        int left = 2*sum1 + 9*noOfQ1;
        int right = 2*sum2 + 9*noOfQ2;
        if(left == right) return false;
        return true;
    }
};