class Solution {
public:
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
     bool helper(int mid , vector<vector<int>>& cells , int row , int col){
        // till mid the water is filled now we will do bfs from everyelement of first row 
        vector<vector<int>>grid(row , vector<int>(col,0));
        for(int i =0; i< mid; i++){
            int newr = cells[i][0]-1;
            int newy = cells[i][1]-1;
            grid[newr][newy] = 1;
        }
         queue<pair<int,int>>hardik;

        vector<vector<bool>>visited(row, vector<bool>(col , false));
        for(int i =0; i<col; i++){
            if(grid[0][i] == 0){
                hardik.push({0,i});
                visited[0][i] = true;
            }
        }
        while(!hardik.empty()){
            auto [currow , curcol] = hardik.front();
            hardik.pop();
            if(currow  == row -1) return true;
            for(auto dir : directions){
                 int nextr = currow + dir[0];
                 int nextc = curcol + dir[1];

                 if(nextr >=0 and nextr < row and nextc >=0 and nextc < col and grid[nextr][nextc] == 0 and visited[nextr][nextc] != true){
                    visited[nextr][nextc] = true;
                    hardik.push({nextr,nextc});
                 }
            }
        }
        return false;

    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // we will do binary search on cell if it is impossible on any day then it is not possible on 
        // later days too and vice versa
        int n = cells.size();
        int s = 0;
        int e = n;
        int ans = INT_MAX;
        while(s<=e){
          int mid = s + (e-s)/2;
          if(helper(mid , cells, row , col)){
            ans = mid;
            s = mid +1;
          }
          else{
            e = mid -1;
          }
        }
        return ans;
        
    }
};