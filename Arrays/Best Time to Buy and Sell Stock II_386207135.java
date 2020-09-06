class Solution {
    public int maxProfit(int[] arr) {
        int n = arr.length;
        int buy = 0; int sell = 0,profit = 0;
        for(int i=1;i<n;i++)
        {
            if(arr[i] >= arr[i-1])
            {
                sell++;
            }
            else
            {
                profit += (arr[sell] - arr[buy]);
                buy = i; sell = i;
            }
        }
        profit += (arr[sell] - arr[buy]);
        return profit;
    }
}
