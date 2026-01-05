class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int smallest = INT_MAX;
        int n = matrix.size();
        int neg = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
               if(matrix[i][j] <0){
                  neg++;
               }
               sum += abs(matrix[i][j]);
               smallest = min(smallest , abs(matrix[i][j]));
            }
        }
        return neg % 2 == 0 ? sum : sum - (2*smallest);
    }
};