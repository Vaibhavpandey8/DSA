bool comp(vector<int> a,vector<int> b){
    return a[1]<b[1];
}


class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        int removal=0;
        sort(intervals.begin(),intervals.end(),comp);
        int end=INT_MIN;
        for(int i=0;i<intervals.size();i++){
            if(end<=intervals[i][0]){
                end=intervals[i][1];
            }
            else{
                removal++;
            }
        }
        return removal;
    }
};
