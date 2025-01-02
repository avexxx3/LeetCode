class Solution {

    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i'|| c == 'o'|| c == 'u');
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> vowels(words.size(), 0);
        vector<int> queryCount(queries.size(), 0);

        int i = 0;
        for(auto& word: words) {
            if(isVowel(word[0]) && isVowel(word[word.length() - 1]))
                vowels[i] = 1;
            i++;
        }

        for(int i=1; i<vowels.size(); i++) {
            vowels[i] += vowels[i-1];
        }

        for(int i=0; i<queries.size(); i++)
            if(queries[i][0] == queries[i][1]) queryCount[i] = isVowel(words[queries[i][0]][0]) && isVowel(words[queries[i][0]][words[queries[i][0]].length() - 1]);
            else queryCount[i] = vowels[queries[i][1]] - (queries[i][0] > 0 ? vowels[queries[i][0] - 1] : 0);

        return queryCount;
    }
};