
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int,vector<int>> hardik;
        for(auto c : nums){
            int ans = 0;
            if(hardik.find(c)!= hardik.end()){
                if(hardik[c].size() == 4){
                for(auto h : hardik[c]){
                    cnt += h;
                }
                }
                continue;

            }
            for(int i =1; i<=c; i++){
                if(c%i == 0){
                    hardik[c].push_back(i);
                    ans++;
                }
                if(ans > 4){
                    break;
                }
            }
            if(ans == 4){
                for(auto h : hardik[c]){
                    cnt += h;
                }
            }
        }
        return cnt;
        
    }
};