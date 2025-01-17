class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xoR = derived[0];
        for(int i=1; i<derived.size(); i++)
            xoR ^= derived[i];

        return !xoR;
    }
};