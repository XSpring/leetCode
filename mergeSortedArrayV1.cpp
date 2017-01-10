/**
    URL: https://leetcode.com/problems/merge-sorted-array/
    No extra storage version
**/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n - 1;
        
        m--;
        n--;
    
        while (m >= 0 || n >= 0)
        {
            if (n < 0 || (m >=0 && nums1[m] >= nums2[n]))
                nums1[len--] = nums1[m--];
            else
                nums1[len--] = nums2[n--];
        }        
        
    }
};

/** 
    There is even a nicer version in LeetCode forum, which is
    Key idea: once all of the numbers from nums2 have been merged into nums1, the rest of the numbers in nums1 that were not moved are already in the correct place.
    
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};    
**/