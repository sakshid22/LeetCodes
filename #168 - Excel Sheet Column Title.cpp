//168

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n!=0)
        {
            n--;
            res=(char)((n)%26 + 'A') + res;
            n/=26;
        }
        return res;
    }
};