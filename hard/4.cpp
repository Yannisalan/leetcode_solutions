//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.The overall run time complexity should be O(log (m+n)).
//Example 1:
//Input: nums1 = [1,3], nums2 = [2]
//Output: 2.00000
//Explanation: merged array = [1,2,3] and median is 2.
//Example 2:

//Input: nums1 = [1,2], nums2 = [3,4]
//Output: 2.50000
//Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

//Constraints:

//nums1.length == m
//nums2.length == n
//0 <= m <= 1000
//0 <= n <= 1000
//1 <= m + n <= 2000
//-106 <= nums1[i], nums2[i] <= 106//

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        while (left <= right) {
            int partition1 = left + (right - left) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int maxLeft1 = (partition1 == 0)
                               ? INT_MIN
                               : nums1[partition1 - 1];

            int minRight1 = (partition1 == m)
                                ? INT_MAX
                                : nums1[partition1];

            int maxLeft2 = (partition2 == 0)
                               ? INT_MIN
                               : nums2[partition2 - 1];

            int minRight2 = (partition2 == n)
                                ? INT_MAX
                                : nums2[partition2];

            if (maxLeft1 <= minRight2 &&
                maxLeft2 <= minRight1) {

                if ((m + n) % 2 == 1) {
                    return max(maxLeft1, maxLeft2);
                }

                return (max(maxLeft1, maxLeft2) +
                        (double)min(minRight1, minRight2)) / 2.0;
            }
            else if (maxLeft1 > minRight2) {
                right = partition1 - 1;
            }
            else {
                left = partition1 + 1;
            }
        }

        return 0.0;
    }
};
