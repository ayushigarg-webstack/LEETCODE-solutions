class Solution {
public:
    bool allOdd(vector<int>& nums1, int minOdd) {
        for(int i =0; i<nums1.size(); i++) {
            if(nums1[i]%2==0) {
                if(nums1[i]-minOdd<1) {
                    return false;
                }
            }
        }
        return true;
    }
    bool allEven(vector<int>& nums1, int minOdd) {
        for(int i =0; i<nums1.size(); i++) {
            if(nums1[i]%2!=0) {
                if(nums1[i]-minOdd<1) {
                    return false;
                }
            }
        }
        return true;
    } 
    bool uniformArray(vector<int>& nums1) {
        int minOdd=INT_MAX;
        int minEven=INT_MAX;
        for(int i=0; i<nums1.size(); i++) {
            if(nums1[i]%2!=0) {
                minOdd=min(minOdd,nums1[i]);
            }    
        }
        //allOdd: sbko odd bnana hai => if a no. is even, usko odd se minus krdo
        //allEven: sbko even bnana hai => if a no. is odd, usko odd se minus krdo
        return (allOdd(nums1, minOdd) || allEven(nums1, minOdd));
    }
};