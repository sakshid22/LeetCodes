//200
class Solution {
    
private:
    void DFS (vector<vector <char>> &grid, vector<vector <int>> &visited, int x , int y)
    {
        if(x<0 || x >= grid.size() || y<0 || y>grid[0].size() || visited[x][y] || grid[x][y]!= '1') return;
        visited[x][y]=1;
        DFS(grid, visited, x-1, y);
        DFS(grid, visited, x, y-1);
        DFS(grid, visited, x+1, y);
        DFS(grid, visited, x, y+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
    int cc=0;
        int cols =grid.size();
        if(cols == 0) return 0;
        int rows = grid[0].size();
        if(rows ==0) return 0;
        vector<vector<int>> visited(cols, vector<int>(rows));
        for(int i=0; i<cols; i++)
        {
            for( int j=0; j<rows ; j++)
            {
                if(grid[i][j]=='1' && visited[i][j] == 0)
                {
                    cc++;
                    DFS(grid,visited, i,j);
                }
            }
        }
       return cc; 
    }
};
