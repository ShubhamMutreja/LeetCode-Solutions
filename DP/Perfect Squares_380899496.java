class Solution {
    HashMap<Integer,Integer> mp = new HashMap<>();
    public int numSquares(int n) {
        if(n==0 || n==1)
            return n;
        if(n<0)
            return (int)1e8;
        int min = (int)1e8;
        
        if(mp.containsKey(n))
            return mp.get(n);
        
        for(int i=1;i<=n/2;i++)
        {
            min = Math.min(min,(n-(i*i)) >= 0 ? numSquares(n-(i*i))+1 : (int)1e8);
            
        }
        mp.put(n,min);
        return min;
    }
}
