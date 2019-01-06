//119

class Solution {
public:
 
  /*  
    vector<int> getRow(int rowIndex) {
     
    vector <int> a(1,1);
        for(int i=1; i<=rowIndex; i++)
            a.push_back((long long) a[i-1]*rowIndex -i+1)/i);
        
        return a;
    }
*/
    
   
    
    vector <int> getRow(int n)
    {
        vector <int> result ={1};
        for(double i=1; i<=n ; i++)
        {
            result.push_back(result.back()* (n-i+1)/i);
            
        }
        return result;
    }
};