class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xors = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Find the rightmost set bit of xors safely
        unsigned int lowbit = static_cast<unsigned int>(xors) & -(static_cast<unsigned int>(xors));

        vector<int> ans(2, 0); // Initialize ans with two elements set to 0

        // Separate `nums` into two groups by `lowbit`.
        for (int num : nums) {
            if (num & lowbit)
                ans[0] ^= num;
            else
                ans[1] ^= num;
        }

        return ans;
    }
};