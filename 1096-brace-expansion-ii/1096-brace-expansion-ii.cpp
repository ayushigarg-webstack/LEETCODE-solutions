class Solution {
public:

    set<string> multiply(set<string>& a, set<string>& b) {
        set<string> res;

        for (string x : a) {
            for (string y : b) {
                res.insert(x + y);
            }
        }

        return res;
    }

    // expression = term (',' term)*
    set<string> parseExpression(string& s, int& i) {

        set<string> res = parseTerm(s, i);

        while (i < s.size() && s[i] == ',') {
            i++;  // skip ','

            set<string> temp = parseTerm(s, i);

            // UNION
            res.insert(temp.begin(), temp.end());
        }

        return res;
    }

    // term = factor*
    set<string> parseTerm(string& s, int& i) {

        // Empty string initially because we concatenate factors
        set<string> res = {""};

        while (i < s.size() &&
               s[i] != '}' &&
               s[i] != ',') {

            set<string> temp = parseFactor(s, i);

            // CONCATENATION
            res = multiply(res, temp);
        }

        return res;
    }

    // factor = letter | '{' expression '}'
    set<string> parseFactor(string& s, int& i) {

        // Single lowercase letter
        if (s[i] >= 'a' && s[i] <= 'z') {

            string ch(1, s[i]);

            i++;

            return {ch};
        }

        // '{'
        i++;

        set<string> res = parseExpression(s, i);

        // '}'
        i++;

        return res;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parseExpression(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};