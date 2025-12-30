class Solution {
public:
    bool helper(vector<vector<int>>hardik){
        int rows = hardik.size();
        int colums = hardik[0].size();
        // check colums sum and row sum
        set<int>sums;
        set<int>dis;
        for(int i =0; i<rows; i++){
            int sum = 0;
            int csum = 0;
            for(int j =0; j<colums; j++){
                if(hardik[i][j] >9 || hardik[i][j] < 1){
                    return false;
                }
                dis.insert(hardik[i][j]);
                sum+= hardik[i][j];
                csum+= hardik[j][i];
                
            }
          
            sums.insert(sum);
            sums.insert(csum);
            
        }
          if(dis.size()!=9){
                return false;
            }
        
        int diag1 = hardik[0][0] + hardik[1][1] + hardik[2][2];
        int diag2 = hardik[0][2] + hardik[1][1] + hardik[2][0];
        sums.insert(diag1);
        sums.insert(diag2);
        if(sums.size() == 1){
            return true;
        }
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int colums = grid[0].size();
        int cnt = 0;
        // finding all the 3*3 grids first
        for(int i =0;i <=rows-3; i++){
            for(int j = 0; j<=colums-3; j++){
                vector<vector<int>>temp;
                for(int k =i; k<i+3; k++){
                    vector<int>temp1;
                    for(int l = j; l<j+3; l++){
                        // if(grid[k][l] >9){
                        //     break;
                        // }
                        temp1.push_back(grid[k][l]);

                    }
                    temp.push_back(temp1);
                }
                if(helper(temp)){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};