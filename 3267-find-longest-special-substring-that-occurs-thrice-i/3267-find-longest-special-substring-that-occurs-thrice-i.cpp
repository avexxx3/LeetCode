class Solution {
public:
    int maximumLength(string s) {
        int max = 0;

        for(int i=0; i < s.length() - max; i++) {
            int lPtr = i;

            string currentSubstr = s.substr(lPtr, max + 1);
            int count = 0;
            int substrLen = currentSubstr.length();

            char ch = currentSubstr[0];
            bool allSameChar = true;

            for(int i=0; i<substrLen; i++)
                if(currentSubstr[i] != ch) {
                    allSameChar = false;
                    break;
                }

            if(!allSameChar)
                continue;

            for(int j=i; j < s.length() - substrLen + 1; j++) {
                int substrCount = 0;
                int ptr = j;

                while(currentSubstr[substrCount] == s[ptr]) {
                    ptr++;
                    substrCount++;
                    if(ptr >= s.length() || substrCount >= substrLen)
                        break;
                }
                
                if(substrCount == substrLen)
                    count++;
            }

            if(count >= 3) {
                max++;
                i = -1;
            }
        }

        return (max!=0) ? max : -1;
    }
};