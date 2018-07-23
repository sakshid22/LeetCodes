//4

class Solution {
public:
 /*   
    int kth(vector <int>&nums1, int m, vector <int>&nums2, int n, int k)
    {
        
        if(m<n)     return kth(nums2,n,nums1,m,k);
        if(n==0)    return nums1[k-1];
        if(k==1)    return min(nums1[0], nums2[0]);
        
        int j=min(n,k/2);
        int i = k-j;
        if(nums1[i-1] > nums2[j-1]) return kth(nums1, i, nums2+j, n-j, k-j);
        return kth(a+i, m-i, b, j, k-i);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m =nums1.size();
        int n =nums2.size();
        int k=(m+n)/2;
        int m1 = kth(nums1,m,nums2,n,k+1)
            if((m+n)%2 == 0)
            {
                int m2 = kth(nums1,m,nums2,n,k);
                return ((double)m1+m2)/2.0;
            }
        return m1;
    }
    */
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int a = nums1.size(), b =nums2.size();
        if(a==0 && b==0)    return 0;
        int count =0, target =(a+b)/2;
        int i=0, j=0, curnum;
        if(a == 0) curnum = nums2[target -1];
        if(b == 0) curnum = nums1[target - 1];
        while(i < a && j<b)
        {
            if(nums1[i] < nums2[j])
            {
                curnum = nums1[i];
                i++;
            }
            else
            {
                curnum = nums2[j];
                j++;
            }
            count ++;
            if(count == target)
                break;
        }
        int nextnum;
        
        if( i ==a)
        {
            curnum = target > count ? nums2[target - count + j -1]: curnum;
            nextnum = nums2[target - count +j];
        }
        else if( j ==b)
        {
            curnum = target > count ? nums1[target - count + i-1]: curnum;
            nextnum = nums1[target - count + i];
        }
        else
            nextnum = min( nums1[i], nums2[j]);
    
    return (a+b) & 1 ? nextnum :( curnum + nextnum) /2.0 ;
    }
};