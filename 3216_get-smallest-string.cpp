class Solution {
public:
    string getSmallestString(string s) {
        int i = 0;
        int j = 1;

        if (s.size() == 1) return s;
        
        while (j!=s.size()){
            int ith = int(s[i])-48;
            int jth = int(s[j])-48;
            if (s[i]>s[j] && jth%2==ith%2){
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                break;
            }
            i++; j++;
        }

        return s;
    }
};