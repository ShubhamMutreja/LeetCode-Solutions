class Solution {
public:
    vector<int> par;
    int find(int src)
    {
        if(par[src] == src)
            return src;
        return par[src] = find(par[src]);
    }
    bool isSimilar(string &str1,string &str2)
{
    int count = 0;
    for(int i=0;i<str1.size();i++)
    {
        if(str1[i] != str2[i] && ++count > 2)
            return false;
    }
    return true;
}
    int numSimilarGroups(vector<string>& A)
{
    int n =A.size();
    for(int i=0;i<n;i++)
    {
        par.push_back(i);
    }
    int count = n;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(isSimilar(A[i],A[j]))
            {
                int p1 = find(i);
                int p2 = find(j);
                if(p1 != p2)
                {
                    par[p1] = p2;
                    count--;
                }
            }

        }
    }
    return count;
}
};
