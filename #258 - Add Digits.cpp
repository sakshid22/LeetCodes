//258

class Solution {
public:
    int addDigits(int num) {
        
        return sol(num);
    }
private:
    int sol(int num)
    {
        if(num<10)
            return num;
        return sol(num/10 + num % 10);
    }
};