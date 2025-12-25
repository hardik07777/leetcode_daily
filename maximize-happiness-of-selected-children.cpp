class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(),h.end());
        int j = 0;
        long long cnt = 0;
        int n = h.size();
        for(int i = n-1; i>=0; i--){
            if(k<=0 || h[i]-j <=0){
                return cnt;
            }
            cnt+= h[i] -j;
            k--;
            j++;

        }
        return cnt;
        
    }
};