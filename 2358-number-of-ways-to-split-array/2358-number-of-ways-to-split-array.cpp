class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int ptr, lC, rC, count;
        ptr = lC = rC = count = 0;

        for(int& num: nums)
            rC += num;

        int size = nums.size();
        while(ptr < size - 1) {
            lC += nums[ptr];
            rC -= nums[ptr];

            count += (lC >= rC);
            ptr++;
        }
    
        return count;
    }
};