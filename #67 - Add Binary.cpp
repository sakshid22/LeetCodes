//67

class Solution {
public:
    string addBinary(string a, string b) {
        
        string result = "";
        int l1 = a.size()-1;
        int l2 = b.size()-1;
        int sum =0;
            while(l1 >=0 || l2>=0)
            {
                int va=0, vb=0;
                if(l1>=0)
                {
                    va = a[l1] - '0';
                    l1--;
                }
                if(l2 >=0)
                {
                    vb = b[l2] - '0';
                    l2--;
                }
                sum = sum+va+vb;
                result = (sum % 2 == 0 ? "0": "1") + result;
                sum = sum/2;
            }
        if(sum ==1)
            result = "1" + result;
        return result;
        
    }
};