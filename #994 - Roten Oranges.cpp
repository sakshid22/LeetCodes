
#994 - Rotten Oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       
        int min = 0;
        int N = grid.size(), M = grid[0].size();
        std::queue<std::pair<int, int>> rotten;
        std::set<std::pair<int,int>> fresh;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(grid[i][j] ==2) rotten.push({i,j});
                else if (grid[i][j] == 1) fresh.insert({i,j});
            }
        }
        
        int count=0, size =rotten.size(), s_size=fresh.size();
        while(count <size)
        {
            int i=rotten.front().first , j=rotten.front().second;
            rotten.pop();
            if( i>0 && fresh.find({i-1,j}) != fresh.end())
            {
                fresh.erase({i-1,j});
                rotten.push({i-1,j});
            }
            if(j>0 && fresh.find({i, j-1})  != fresh.end())
            {
                fresh.erase({i, j-1});
                rotten.push({i, j-1});
            }
            if(i<N && fresh.find({i+1, j})   != fresh.end())
            {
                fresh.erase({i+1,j});
                rotten.push({i+1, j});
            }
            if(j<M && fresh.find({i, j+1})  !=  fresh.end())
            {
                fresh.erase({i,j+1});
                rotten.push({i, j+1});      
            }
            count +=1;
            if(count == size)
            {
                count=0;
                size = rotten.size();
                min++;
            }       
        }
        
        if(!fresh.empty()) return -1;
        if(min ==0) return 0;
        return min-1;
    }
};