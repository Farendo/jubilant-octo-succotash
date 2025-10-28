/*
349. Intersection of Two Arrays

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        bool numInArray = false;
        for(size_t i = 0; i < nums1.size(); i++ )
        {
            numInArray = false;
            for(size_t j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    nums2.erase(nums2.begin() + j);
                    numInArray = true;
                }
            }
            if(numInArray)
                {
                    result.push_back(nums1[i]);
                    for(size_t k = i + 1; k < nums1.size();k++)
                    {
                        if(nums1[k]==nums1[i])
                            nums1.erase(nums1.begin() + k);
                    }
                    nums1.erase(nums1.begin() + i);
                    i--;
                }
        }
        return result;
    }
};