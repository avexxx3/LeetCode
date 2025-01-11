class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> arr(26, 0);
        for(char &ch: s)
            arr[ch - 'a']++;

        int solos = 0;
        int doubles = 0;
        int i=0;
        while(i<26) 
            if(arr[i] > 0)
                if(arr[i]%2) {
                    solos++;
                    arr[i]--;
                } else {
                    arr[i] -= 2;
                    doubles++;
                }
            else i++;

            if(k < solos)
                return false;

            k -= solos;
            k -= doubles * 2;

            return k<=0;
    }
};