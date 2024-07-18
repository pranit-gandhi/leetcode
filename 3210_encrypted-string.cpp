class Solution {
public:
    string getEncryptedString(string s, int k) {
        string res = "";
        for (size_t i=0; i<s.size(); i++){
            res+=s[(i+k)%s.size()];
        }
        return res;
    }
};