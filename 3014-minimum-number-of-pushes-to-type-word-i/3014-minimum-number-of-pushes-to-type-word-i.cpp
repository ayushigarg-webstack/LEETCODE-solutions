class Solution {
public:
    int minimumPushes(string word) {
        if(word.length()<=8) return word.length();
        int pushes=0;
        for (int i = 0; i < word.length(); i++) {
            pushes += (i / 8) + 1;
        }
        return pushes;
    }
};