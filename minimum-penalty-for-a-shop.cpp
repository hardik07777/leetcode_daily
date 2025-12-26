class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        // every index of pre[i] should store how many y are infront of it and n below it
        vector<int>pren(n+1,0);
        vector<int>sufy(n+1,0);
      

        for(int i =1; i<=n; i++){
            if(customers[i-1] == 'N'){
            pren[i] = pren[i-1] + 1;
            }
            else{
                pren[i] = pren[i-1];
            }
        }
        for(int i =n-1; i>=0; i--){
            if(customers[i] == 'Y'){
            sufy[i] = sufy[i+1] + 1;
            }
            else{
                sufy[i] = sufy[i+1];
            }
        }
        int fix = INT_MAX;
        int penality = 0;
        int ans = 0;
        for(int i =0; i<=n; i++){
              penality = pren[i] + sufy[i];
              if(penality < fix){
                ans = i;
                fix = penality;
              }
              else if(penality == fix){
                ans = min(ans,i);
              }
        }
        return ans;

        
    }
};