class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Checks for smaller cases
        // Checking sizes 1 and 2 because they are less than 3
        if (nums.size() == 1) return nums;
        if (nums.size() == 2) {
            if (nums[0] == nums[1]) return { nums[0] };
            return nums;
        }

        // Modified Boyer-Moore Voting
        int count1 = 0;
        int count2 = 0;
        int candidate1;
        int candidate2;

        for (const auto num : nums) {
            if      (count1 == 0 && num != candidate2) candidate1 = num;
            else if (count2 == 0 && num != candidate1) candidate2 = num;
            
            if      (num == candidate1) ++count1;
            else if (num == candidate2) ++count2;
            else {
                --count1;
                --count2;
            }
        }

        // Confirmation passes
        int freq1 = 0;
        int freq2 = 0;
        for (const auto num : nums) 
            if      (num == candidate1) ++freq1;
            else if (num == candidate2) ++freq2;

        vector<int> majorityElements;
        if (freq1 > nums.size() / 3) majorityElements.emplace_back(candidate1);
        if (freq2 > nums.size() / 3) majorityElements.emplace_back(candidate2);

        return majorityElements;
    }
};