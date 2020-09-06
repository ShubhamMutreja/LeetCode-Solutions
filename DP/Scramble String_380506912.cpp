class Solution {
public:
    map<string,bool>mp;
    bool isScramble(string a, string b) {
        if(a.length() != b.length())
            return false;
        //cout<<a<<" " <<b<<endl;
        if(a.compare(b) == 0)
        {
            return true;
            
        }
        string key=a;
        key.push_back('_');
        key.append(b);
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }
        if(a.length()<=1)
            return false;
        int n = a.length();
        bool f = false;
        for(int i = 1;i<n;i++)
        {
            bool swap_yes = isScramble(a.substr(0,i),b.substr(0,i)) &&  isScramble(a.substr(i),b.substr(i));
            bool swap_no  = isScramble(a.substr(0,i),b.substr(n-i)) &&  isScramble(a.substr(i),b.substr(0,n-i));
            if(swap_yes || swap_no)
            {
                f =  true; 
                break;
            }
                
        }
        return mp[key] = f;
    }
};
