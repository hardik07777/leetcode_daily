class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for(auto a : apple){
            total += a;
        }
        // we have to find the min capacity or the min sum of cacpcity that is equal to total
        sort(capacity.begin(), capacity.end());
        int cnt = 0;
        for(int i = capacity.size() -1; i>=0; i--){
            if(total <=0){
                return cnt;
                break;
            }
            total -= capacity[i];
            cnt++;
        }
        return cnt;

    }
};