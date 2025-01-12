class Solution {
public:
    bool canBeValid(string s, string locked) {
        int l = s.length();

        if(l%2)
            return false;

        int freeC = 0;
        int counter = 0;

        for(int i=0; i<l; i++) {
            if(locked[i] == '0')
                freeC++;
            else if(s[i] == '(')
                counter++;
            else if(counter == 0)
                if(freeC <= 0)
                    return false;
                else
                    freeC--;
            else
                counter--;
        }

        if(counter > freeC)
            return false;

        counter = 0;
        freeC = 0;
        for(int i=l-1; i>=0; i--) {
            if(locked[i] == '0')
                freeC++;
            else if(s[i] == ')')
                counter++;
            else if(counter == 0)
                if(freeC <= 0)
                    return false;
                else
                    freeC--;
            else
                counter--;
        }

        if(counter > freeC)
            return false;

        return true;
    }
};