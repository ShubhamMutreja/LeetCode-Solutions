class Solution {
public:
    typedef long long int ll;
    #define mod 1000000007;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,n=nums1.size(),m=nums2.size();
        ll s1=0,s2=0,ans = 0;
        
        while(i < n && j < m)
        {
            if(nums1[i] < nums2[j])
            {
                s1 += nums1[i];
                i++;
            }
            else if(nums1[i] > nums2[j])
            {
                s2 += nums2[j];
                j++;
            }
            else
            {
                ans = ans + max(s1,s2) + nums1[i];
                s1 = 0; s2 = 0;
                i++;j++;
            }
        }
        while(i < n)
        {
            s1 += nums1[i];
            i++;
        }
        while(j < m)
        {
            s2 += nums2[j];
            j++;
        }
        ans = (ans + max(s1,s2))%mod;
        return ans;
    }
};