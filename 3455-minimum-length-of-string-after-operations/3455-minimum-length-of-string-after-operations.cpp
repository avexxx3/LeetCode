class Solution {
public:
    int minimumLength(string s) {
        vector<int> str(26, 0);
        for(char& ch: s)
            str[ch - 'a']++;

        int count = 0;
        for(int i=0; i<26; i++)
            if(str[i])
                if(str[i]%2)
                    count++;
                else
                    count+=2;
        
        return count;
    }
};