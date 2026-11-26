class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        n=n-10;
        int i = 9;
        while(n-i>=0) {
            n=n-i;
            i--;
        }
        if(i%2==0) return false;
        else return true;
    }
};