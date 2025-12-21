class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int colums = strs[0].size();
        int cnt = 0;
        vector<bool>autosorted(row , false);
        for(int i = 0; i<colums; i ++){
            bool flag = true;
            for(int j =1; j <row; j++){
                
                if(!autosorted[j-1] and strs[j][i] < strs[j-1][i]){
                    // we have to check hair if the strs[j][i] == strs[j -1][i] then we weill cehk other colums too 
                    cnt++;
                    flag = false;
                    break;
                 }
                
            }
            if(!flag) continue;
            for(int j =0; j< row-1; j++){
              autosorted[j] = autosorted[j] | strs[j][i] < strs[j+1][i];
            }
        }
        return cnt;
        
    }
};