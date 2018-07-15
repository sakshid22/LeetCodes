//417
class Solution {

public:
    
    void floodfill(vector<vector<int>> &matrix, vector<vector<bool>> &ocean, int i, int j, int preValue){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() ||ocean[i][j] ||matrix[i][j] <preValue)
            return;
        ocean[i][j] = true;
         floodfill(matrix, ocean, i+1, j, matrix[i][j]);
         floodfill(matrix, ocean, i-1, j, matrix[i][j]);
         floodfill(matrix, ocean, i, j+1, matrix[i][j]);
         floodfill(matrix, ocean, i, j-1, matrix[i][j]);
    
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    
        if(matrix.size() == 0)
            return {};
        vector<pair<int,int>> result;
        vector<vector<bool>>atlantic(matrix.size(), vector<bool>(matrix[0].size(),false)),
                            pacific(matrix.size(), vector<bool>(matrix[0].size(), false));
        
        for(int i =0; i<matrix.size(); ++i)
        {
            floodfill(matrix, pacific, i, 0, INT_MIN);
            floodfill(matrix, atlantic, i, matrix[0].size() -1, INT_MIN );
        }
        
        for(int j=0; j<matrix[0].size(); ++j)
        {
            floodfill(matrix, pacific, 0, j, INT_MIN);
            floodfill(matrix, atlantic, matrix.size() -1, j, INT_MIN);
        }
        
        for(int i=0; i<matrix.size(); ++i)
        {
            for( int j=0; j<matrix[i].size(); ++j)
            {
                if(pacific[i][j] && atlantic[i][j])
                    result.push_back(pair<int, int>(i,j));
            }
        }
        return result;
    
    }
};