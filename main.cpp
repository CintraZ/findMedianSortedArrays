#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
double findKth(vector<int>& nums1, vector<int>& nums2, int k) {
    if(nums1.size() > nums2.size()) {
        return findKth(nums2, nums1, k);
    }
    if(nums1.empty()) {
        return nums2[k - 1];
    }
    if(k == 1) {
        return min(nums1[0], nums2[0]);
    }
    int size1 = nums1.size();
    int pa = min(k / 2, size1);
    int pb = k - pa;

    if(nums1[pa - 1] < nums2[pb - 1]) {
        vector<int> tmp1;
        tmp1.assign(nums1.begin() + pa,nums1.end());
        return findKth(tmp1,nums2,k - pa);
    } else if(nums1[pa - 1] > nums2[pb - 1]) {
        vector<int> tmp2;
        tmp2.assign(nums2.begin()+pb, nums2.end());
        return findKth(nums1, tmp2, k - pb);
    } else {
        return nums1[pa - 1];
    }

}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();

        if(total & 0x1) {
            return findKth(nums1, nums2, total / 2 + 1);
        } else {
            return (findKth(nums1, nums2, total/2) + findKth(nums1, nums2, (total/2 + 1)))/2;
        }
    }
};

int main() {
    Solution so;
    vector<int> nums1,nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(6);
    cout << nums1[0] << endl;

    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(5);
    cout << nums2[0] << endl;
    cout << so.findMedianSortedArrays(nums1,nums2);
    return 0;
}
