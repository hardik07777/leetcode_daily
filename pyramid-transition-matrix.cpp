class Solution {
public:
    unordered_map<string,bool>t;
    bool solve(unordered_map<string,vector<char>>& helper ,string current , int i , string next){
        // base case 
        if(current.size() == 1){
            return true;
        }
        if(i == current.size()-1){
            return solve(helper , next , 0, "");
        }
        string key = current + to_string(i) + next;
        if(t.count(key)){
            return t[key];
        }
        string pair = current.substr(i , 2);
        if(!helper.count(pair)){
            return t[key] = false;
        }
        for(auto ch : helper[pair]){
            next.push_back(ch);// do
            if(solve(helper , current , i+1 , next)){ // explore
                return t[key] = true;
            }
            // bacltrack
            next.pop_back();
        }
        return t[key]= false;
        
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>>helper;
        for(auto c : allowed){
           helper[c.substr(0,2)].push_back(c[2]);
        }
        return solve(helper , bottom , 0 , "");
    }
};