//498
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    
          if(matrix.empty() || matrix[0].empty())
                return {};
        int m =matrix.size();
        int n =matrix[0].size();
        vector <int> res(m*n);
         
    //    cout<<m<<n;
        int c=0, r=0;
      
        for(int i=0; i<m*n; i++)
        {
            res[i]=matrix[r][c];
            if((r+c) % 2 ==0) // Even -up
            {
                if(c==n-1)      ++r;   //last column
                else if(r==0)   ++c;   //only 1 column
                else         
                {--r;
                 ++c;
                } // row dec col inc
            }
            else            // Odd - down
            {
                if(r==m-1)      ++c;    // last row
                else if(c==0)   ++r;    // only 1 row
                else        
                {++r;
                 --c;
                } // row inc col dec
            }
        }
      return res;
    }
};