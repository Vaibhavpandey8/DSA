bool comp(pair<int,int> a,pair<int,int> b){
    return (double)a.first/a.second>(double)b.first/b.second;
}



class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        vector<pair<int,int>>knp;
        for(int i=0;i<n;i++){
            knp.push_back({val[i],wt[i]});
        }
        sort(knp.begin(),knp.end(),comp);
        
        double profit=0;
        int i=0;
        while(capacity&&i<n){
            if(capacity>=knp[i].second){
                profit+=knp[i].first;
                capacity-=knp[i].second;
            }
            else{
                profit+=capacity * ((double)knp[i].first/knp[i].second);
                capacity=0;
            }
            i++;
        }
        return profit;
        
    }
};
