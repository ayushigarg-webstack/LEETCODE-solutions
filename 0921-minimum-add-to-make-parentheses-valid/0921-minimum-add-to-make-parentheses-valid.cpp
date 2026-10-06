class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s=="") return true;
        int opening = 0;
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i]=='(') {
                opening++;
            } else if(s[i]==')') {
                opening--;
                if(opening<0) {
                    count++;
                    opening=0;
                }    
            }
        }
        return (opening+count);
    }
};