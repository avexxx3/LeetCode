class Solution {
public:
    vector<int> minOperations(string boxes) {
        int l = boxes.length();
        vector<int> forward(l, 0);
        vector<int> backward(l, 0);

        int count = 0;
        for(int i=1; i<l; i++) {
            if(boxes[i-1] == '1')
                count++;

            forward[i] = forward[i-1] + count;
            
        }

        count = 0;
        for(int i=l-2; i>-1; i--) {
            if(boxes[i+1] == '1')
                count++;

            backward[i] = backward[i  + 1] + count;
        }

        for(int i=0; i<l; i++)
            backward[i] += forward[i];

        return backward;
    }
};