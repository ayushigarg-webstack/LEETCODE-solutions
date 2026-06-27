class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        typedef long long ll;
        map<ll,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        int ans = 1;
        if(mp.count(1))
        {
            ans = max(ans, mp[1] % 2 == 0 ? mp[1]-1 : mp[1]);
        }
        for(auto &[x,count] : mp)
        {
            if(x==1) continue;
            ll curr = x;
            int len = 0;
            while(mp[curr] >= 2)
            {
                len += 2;
                curr *= curr;
                if(curr > 1e18) break;
            }
            if(mp[curr] >= 1) len += 1;
            else len -= 1;
            ans = max(ans, len);
        }
        return ans;
    }
};