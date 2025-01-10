class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> characterList(26, 0);
        for(string& word: words2) {
            vector<int> wordCount(26, 0);
            for(char& ch: word)
                wordCount[ch - 'a']++;
            for(int i=0; i<26; i++)
                characterList[i] = max(characterList[i], wordCount[i]);
        }

        vector<string> res;

        for(string& word: words1) {
            vector<int> cL = characterList;
            for(char& ch: word)
                cL[ch - 'a']--;

            bool flag = 0;
            for(int& count: cL) {
                if(count > 0) {
                    flag = 1;
                    break;
                }
            }

            if(!flag)
                res.emplace_back(word);
        }     

        return res;
    }
};