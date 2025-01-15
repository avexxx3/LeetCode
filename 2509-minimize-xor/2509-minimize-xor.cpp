class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ogNum1 = num1;

        int bits = 0;
        while(num2 != 0) {
            bits += (num2 & 1);
            num2 = num2 >> 1;
        }   

        vector<int> num(32, 0);
        vector<int> numGen(32, 0);
        
        int index = 31;

        while(num1 != 0) {
            num[index--] = num1 & 1;
            num1 = num1 >> 1;
        }
        
        for(int i=0; i<32; i++) {
            if(num[i] == 1) {
                numGen[i] = 1;
                if(--bits == 0)
                    break;
            }
        }

        index = 31;
        while(bits) {
            if(!numGen[index]) {
                numGen[index] = 1;
                bits--;
            }
            index--;
        }

        int generatedNum = 0;
        long sum = 1;
        for(int i=31; i>=0; i--) {
            generatedNum += numGen[i] * sum;
            sum *= 2;
        }

        return generatedNum;
    }   
};