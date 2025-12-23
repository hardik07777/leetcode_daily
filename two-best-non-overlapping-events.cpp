class Solution {
public:
    int t[100001][3];
    int binary(vector<vector<int>> &events , int i){
        int s = 0;
        int e = events.size() - 1;
        int ans = events.size();
         while(s<=e){
            int mid = s + (e-s)/2;
            if(events[mid][0] > events[i][1]){
                ans = mid;
                e = mid - 1;

            }
            else{
                s = mid + 1;
            }
         }
         return ans;

    }
    int helper(vector<vector<int>>& events , int i , int count){
        // base case 
        if( count == 2 || i >= events.size()){
            return 0;
        }
         // recursive case 
         // on each element just see take or not take 
         if(t[i][count] != -1){
            return t[i][count];
         }
         int nextperfectindex = binary(events , i);
         int take= events[i][2] + helper(events, nextperfectindex , count + 1);
         
         int nottake = helper(events, i +1 , count );
         return t[i][count] =  max(take ,nottake);

    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        memset(t,-1 , sizeof(t));
        return helper(events , 0 , 0);
        
    }
};
