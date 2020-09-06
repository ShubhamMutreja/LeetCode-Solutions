class Solution {
public:
    int count(const vector<int>& nums,int si,int ei,int num)
    {
        unsigned int c = 0;
        for(unsigned int i=si;i<=ei;i++)
        {
            if(nums[i] == num)
            {
                c++;
            }
        }
        return c;
    }
    int div(vector<int>& nums,int si,int ei)
    {
        if(si > ei)
            return -1;
        if(si == ei)
            return nums[si];
        int mid = si + (ei - si) / 2;
        int left = div(nums,si,mid);
        int right = div(nums,mid+1,ei);
        if(right != -1 && left == -1)
        {
            unsigned int num = count(nums,si,ei,right);
            if(num > (ei-si+1)/2)
            {
                return right;
            }
            else
            {
                return -1;
            }
        }
        else if(right == -1 && left != -1)
        {
            unsigned int num = count(nums,si,ei,left);
            if(num > (ei-si+1)/2)
            {
                return left;
            }
            else
            {
                return -1;
            }
        }
      
        else if(right != -1 && left != -1)
        {
            unsigned  int rnum = count(nums,si,ei,right);
            unsigned  int lnum = count(nums,si,ei,left);
            //cout<<left<<" "<<right;
            if(lnum > (ei-si+1)/2)
            {
                return left;
            }
            else if(rnum > (ei-si+1)/2)
            {
                return right;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
        
    }
    int majorityElement(vector<int>& nums) {
        return div(nums,0,nums.size()-1);
    }
};
