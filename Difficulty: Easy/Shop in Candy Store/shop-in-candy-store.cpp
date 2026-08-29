class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
        vector<int> ans;
        int max=0;
        int min=0;
        int i=0,j=prices.size()-1;
        while(i<=j){
            min+=prices[i];
            i++;
            j-=k;
        }
        i=prices.size()-1;
        j=0;
        while(i>=j){
            max+=prices[i];
            i--;
            j+=k;
        }
        ans.push_back(min);
        ans.push_back(max);
        return ans;
    }
};