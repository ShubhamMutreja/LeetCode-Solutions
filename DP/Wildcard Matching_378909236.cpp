class Solution {
public:
    bool dynamic(const string& s, const string& p, int p1, int p2, vector<vector<int>>& aux){
        int m=s.size(), n=p.size();
        bool ans=false;
        if(p1>=m && p2>=n)
            return true;
        if(p2>=n)
            return false;
        if(aux[p1][p2]!=-1)
            return aux[p1][p2];
        if(p1<m && (s[p1]==p[p2] || p[p2]=='?'))
            ans=dynamic(s, p, p1+1, p2+1, aux);
        else if(p[p2]=='*')
            if(p1<m)
                ans=dynamic(s, p, p1+1, p2, aux) || dynamic(s, p, p1, p2+1, aux);
            else
                ans=dynamic(s, p, p1, p2+1, aux);
        aux[p1][p2]=ans;
        return ans;
    }
    
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        vector<vector<int>> aux(m+1, vector<int>(n+1, -1));
        return dynamic(s, p, 0, 0, aux);
    }
};
