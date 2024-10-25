class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;

        vector<int> rotated(size);

        for (int i = 0; i < size; i++) {
            rotated[(i + k) % size] = nums[i];
        }

        for (int i = 0; i < size; i++) {
            nums[i] = rotated[i];
        }       
    }
};