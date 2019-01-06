//682

class Solution {
public:
    int calPoints(vector<string>& ops) {
       
        stack <int> s;
        int a,b;
        int res=0;
            for(auto op: ops)
            {
                if(s.empty())
                {
                    s.push(getInt(op));
                }
                else
                {
                    if(op == "+")
                    {
                        a=s.top();
                        s.pop();
                        b=s.top();
                        s.push(a);
                        s.push(a+b);
                        
                    }
                    else if (op == "C")
                        s.pop();
                    else if (op == "D")
                    {
                        a=s.top();
                        s.push(a*2);
                    }
                    else
                        s.push(getInt(op));
                }
            }
        
        while(!s.empty ())
        {
            res = res+s.top();
            s.pop();
        
        }
        return res;
    }
    
    int getInt(string s)
    {
        int a;
        stringstream ss;
        ss<<s;
        ss>>a;
        return a;
    }
};