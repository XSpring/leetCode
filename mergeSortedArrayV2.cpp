/**
    URL: https://leetcode.com/problems/merge-sorted-array/
    Extra storage O(N) version
**/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> vec3;
        
        vec3.reserve(m + n);
        int id1 = 0, id2 = 0;
   
        while (id1 < m && id2 < n)
        {
            if (nums1[id1] <= nums2[id2])
            {
                vec3.push_back(nums1[id1]);
                id1++;
            }
            else
            {
                vec3.push_back(nums2[id2]);
                id2++;
            }
        }
   
        if (id1 < m)
            while (id1 < m)
                vec3.push_back(nums1[id1++]);
    
        if (id2 < n)
            while (id2 < n)
                vec3.push_back(nums2[id2++]);
    
        nums1 = vec3;
    }
};