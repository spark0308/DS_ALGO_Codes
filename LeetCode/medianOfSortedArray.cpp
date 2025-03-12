//4. Median of Two Sorted Arrays
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int binarySearchIndex(vector<int> array, int num, int left, int right){
        int middle = (left+right)/2;
        if(middle == left){
            if(array[left] < num) return left+1;
            else return left;
        }

        if(array[middle] == num) return middle;

        if(array[middle] < num) return binarySearchIndex(array, num, middle, right);
        return binarySearchIndex(array, num, left, middle);
    }

    int getInsertIndex(vector<int> mergeArray, int num){
        int n = mergeArray.size();
        int left = 0;
        int right = n-1;
        if(n == 0) return 0;
        if(mergeArray[right] < num) return n;
        return binarySearchIndex(mergeArray, num, left, right);
    }

    vector<int> mergeTwoArrays(vector<int> nums1, vector<int> nums2){
        vector<int> mergedArray;
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 == 0) return nums2;
        if(n2 == 0) return nums1;

        if(n1 > n2){
            mergedArray = nums1;
            for(auto x: nums2){
                mergedArray.insert(mergedArray.begin() + getInsertIndex(mergedArray, x), x);
            }
        }
        else{
            mergedArray = nums2;
            for(auto x: nums1){
                mergedArray.insert(mergedArray.begin() + getInsertIndex(mergedArray, x), x);
            }
        }

        return mergedArray;
    }

    vector<int> mergeTwoArrayAndSort(vector<int> nums1, vector<int> nums2){
        vector<int> ans = nums1;
        for(int x: nums2) ans.push_back(x);

        sort(ans.begin(), ans.end());

        return ans;
    }

    vector<int> mergeTwoArrayTwoPointer(vector<int> nums1, vector<int> nums2){
        int pointer1 = 0;
        int pointer2 = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> mergeArray;

        while (pointer1 < n1 && pointer2 < n2)
        {
            if(nums1[pointer1] < nums2[pointer2]){
                mergeArray.push_back(nums1[pointer1]);
                pointer1++;
            }
            else{
                mergeArray.push_back(nums2[pointer2]);
                pointer2++;
            }
        }

        while (pointer1 < n1)
        {
            mergeArray.push_back(nums1[pointer1]);
                pointer1++;
        }
        
        while (pointer2 < n2)
        {
            mergeArray.push_back(nums2[pointer2]);
                pointer2++;
        }
        
        return mergeArray;
    }

    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray = mergeTwoArrayTwoPointer(nums1, nums2); // Time complexity O((m+n))  Best time complexity
        //vector<int> mergedArray = mergeTwoArrayAndSort(nums1, nums2); // Time complexity O((m+n)log(m+n))  Less efficient
        //vector<int> mergedArray = mergeTwoArrays(nums1, nums2);  //Time complexity O(mn)  Worst efficiency
        int n = mergedArray.size();

        if(n%2 == 0){
            return (double)((double)mergedArray[(n/2)-1] + (double)mergedArray[(n/2)])/2;
        }

        return mergedArray[(n/2)];
    }
};

int main() {
    Solution sln = Solution();
    int m, n;
    cin>>m>>n;
    vector<int> nums1(m);
    vector<int> nums2(n);

    for(int &x: nums1) cin>>x;
    for(int &x: nums2) cin>>x;

    cout<<sln.findMedianSortedArrays(nums1, nums2)<<endl;
}