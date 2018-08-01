//461

class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int count =0;
        int z= x^y;
        while(z>0)
        {
            if(z%2 ==1)
            {
                count++;
            }
            z=z/2;
        }
        return count;
    }
};