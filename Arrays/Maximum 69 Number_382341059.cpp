class Solution {
public:
    int maximum69Number (int num) {
        int flag {};
        string temp {};
        string s = to_string(num);
        for(auto i : s){
            if(i == '9'){
                temp += "9";
            } else if(i == '6' && flag == 0){
                temp += "9";
                flag = 1;
            } else if(i == '6'){
                temp += "6";
            }
        }
        int result = stoi(temp);
        return result;
    }
};
