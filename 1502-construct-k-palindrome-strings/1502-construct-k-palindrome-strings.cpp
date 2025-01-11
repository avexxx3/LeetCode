class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> arr(26, 0);
        for(char &ch: s)
            arr[ch - 'a']++;

        int solos = 0;
        int doubles = 0;
    
        for(int &num: arr)
            if(num > 0) {
                if(num%2) {
                    solos++;
                    num--;
                }

                doubles += num/2;
            }

            if(k < solos)
                return false;

            k -= solos;
            k -= doubles * 2;
            
            return k<=0;
    }
};