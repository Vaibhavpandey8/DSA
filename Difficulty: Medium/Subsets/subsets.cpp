class Solution {
  public:
    void findsubset(vector<int>& arr,vector<int>& ans,int i, vector<vector<int>>& subset){
        if(i==arr.size()){
            return;
        }
        ans.push_back(arr[i]);
        findsubset(arr,ans,i+1,subset);
        subset.push_back({ans});
        ans.pop_back();
        findsubset(arr,ans,i+1,subset);
        
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<int> ans;
        vector<vector<int>> subset;
        subset.push_back(ans);
        int i=0;
        findsubset(arr,ans,i,subset);
        return subset;
    }
};