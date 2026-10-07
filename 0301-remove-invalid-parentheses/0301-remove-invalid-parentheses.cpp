class Solution {
public:
    int maxLength;
    unordered_set <string> ans;

    void solve(int i, string &s, int count, string &curr){

        if(count<0) return;
         int n= s.length();

        if(i==n){

            if(count==0){

                if(curr.length() >maxLength){

                    maxLength= curr.length();
                    ans.clear();
                }

                if(curr.length() == maxLength){

                    ans.insert(curr);

                }

            }
            return;
        }

        if(s[i] != '(' && s[i] != ')'){

            curr.push_back(s[i]);

            solve(i+1, s, count, curr);

            curr.pop_back();

            return;
        }

        curr.push_back(s[i]);

        solve(i+1, s, count + (s[i] == '(' ? 1 : -1), curr);

        curr.pop_back();

        solve(i+1, s, count, curr);
    }
    vector<string> removeInvalidParentheses(string s) {
        
        int n= s.length();
        
          maxLength=0;
        

        string curr="";

        solve(0,s,0,curr);

        return vector<string> (ans.begin(), ans.end());
    }
};