class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int lis = 0;
        vector<int>dp(strs[0].size(),1);
        for(int i=0; i< strs[0].size(); i++){
            for(int j =0; j<i; j++){
                bool flag = true;
                for(int k =0; k<strs.size(); k++){
                    if(strs[k][i] < strs[k][j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                   dp[i] = max(dp[i] , dp[j]+1);
                }
            }
            lis = max(lis , dp[i]);
        }
        return strs[0].size() - lis;
        
    }
};