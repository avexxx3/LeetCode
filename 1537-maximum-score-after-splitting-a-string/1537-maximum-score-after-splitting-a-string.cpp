class Solution {
public:
    int maxScore(string s) {
        int lCount = 0;
        int rCount = 0;
        int ptr = 1;
        
        while(ptr < s.length())
            if(s[ptr++] == '1')
                rCount++;

        ptr = 0;
        if(s[ptr++] == '0')
            lCount++;

        int maxC = lCount + rCount;

        while(ptr < s.length()) {
            if(s[ptr] == '1')
                rCount--;
            else
                lCount++;

            maxC = max(maxC, lCount + rCount);
            ptr++;
        }

        return maxC;
    }
};