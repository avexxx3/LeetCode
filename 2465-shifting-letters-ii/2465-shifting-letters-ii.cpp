class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> word(s.length(), 0);
        int l = word.size();
        
        for(auto& shift: shifts)
            if(!shift[2]) {
                word[shift[0]] += -1;
                if(shift[1] + 1 < l) word[shift[1] + 1] += 1;
            }
            else {
                word[shift[0]] += 1;
                if(shift[1] + 1 < l) word[shift[1] + 1] += -1;
            }


        for(int i=1; i < l; i++) 
            word[i] += word[i-1];
        
        for(int i=0; i<l; i++) {
            word[i] += s[i] - 'a';
            while(word[i] < 0)
                word[i] += 26;
                
            word[i] = word[i] % 26;
            s[i] = word[i] + 'a';
        }

        return s;
    }
};