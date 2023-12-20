class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1 + len2;

        int half_first = total / 2;
        int half_second = half_first - 1;
        int index_first = 0;
        int index_second = 0;
        int i = 0;
        int j = 0;
        int cnt = 0;
        while (i < len1 && j < len2)
        {
            if (nums1[i] < nums2[j])
            {
                if (cnt == half_first)
                {
                    index_first = nums1[i];
                    cnt++;
                    break;
                }

                if (cnt == half_second)
                {
                    index_second = nums1[i];
                }
                i++;
                cnt++;
            }
            else
            {
                if (cnt == half_first)
                {
                    index_first = nums2[j];
                    cnt++;
                    break;
                }

                if (cnt == half_second)
                {
                    index_second = nums2[j];
                }

                j++;

                cnt++;
            }
        }
        while (i < len1)
        {
            if (cnt == half_first)
            {
                index_first = nums1[i];
                cnt++;
                break;
            }
            if (cnt == half_second)
            {
                index_second = nums1[i];
            }
            i++;
            cnt++;
        }
        while (j < len2)
        {
            if (cnt == half_first)
            {
                index_first = nums2[j];
                cnt++;
                break;
            }

            if (cnt == half_second)
            {
                index_second = nums2[j];
            }
            j++;

            cnt++;
        }
        if (total % 2 == 0)
        {
            return (index_first + index_second) / 2.0;
        }
        return index_first;
    }

};