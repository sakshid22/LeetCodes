// #997 - Find the Town Judge

class Solution {
    public int findJudge(int N, int[][] trust) {
      
         int[][] trustTable = new int[N][2];
        for(int i=0; i<trust.length; i++)
        {
            trustTable[trust[i][0]-1][0]++;
            trustTable[trust[i][1]-1][1]++;    
        }
        for(int i=0; i<trustTable.length;i++)
        {
            if(trustTable[i][0] == 0 && trustTable[i][1] == N-1)
                return i+1;
        }
    
        
       return -1; 
    }
        
        

}