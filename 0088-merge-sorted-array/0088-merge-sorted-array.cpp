class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums;
        int i=0;
        int j=0;
        while(i < nums1.size() - n && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                nums.emplace_back(nums1[i++]);
            }
            else
                nums.emplace_back(nums2[j++]);
        }

        while(i < nums1.size() - n)
            nums.emplace_back(nums1[i++]);

        while(j < nums2.size())
            nums.emplace_back(nums2[j++]);

        nums1 = nums;
    }
};