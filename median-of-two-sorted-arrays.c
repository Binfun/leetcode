//https://leetcode.com/problems/median-of-two-sorted-arrays/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
        int LA,RA,LB,RB;
        unsigned int temp = ~0;
        int MAX = temp >> 1,MIN = (-1-MAX);
        int CA,CB;
        int lo,hi;
        //nums1 long, nums2 short
        if (nums2Size > nums1Size)
                return findMedianSortedArrays(nums2,nums2Size,nums1,nums1Size);
        if (nums2Size == 0)
                return (double)(nums1[(nums1Size-1)/2]+nums1[(nums1Size/2)])/2;
        lo = 0;
        hi = nums2Size * 2;
        while(lo <= hi){
                CB = (lo + hi)/2;
                CA = nums1Size + nums2Size - CB;
                LA = (CA == 0)?MIN:nums1[(CA-1)/2];
                RA = (CA == nums1Size * 2)?MAX:nums1[(CA)/2];
                LB = (CB == 0)?MIN:nums2[(CB-1)/2];
                RB = (CB == nums2Size * 2)?MAX:nums2[(CB)/2];
                if (LA > RB)
                        lo = CB + 1;
                else if (LB > RA)
                        hi = CB - 1;
                else
                        return (double)((LA>=LB?LA:LB)+(RA<=RB?RA:RB))/2;
        }
        return -1;
}

