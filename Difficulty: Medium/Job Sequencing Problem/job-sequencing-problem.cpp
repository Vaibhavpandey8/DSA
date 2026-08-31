bool comp(pair<int,int> a,pair<int,int>  b){
    return a.second>b.second;
}

int find(int num,vector<int>& Parent){
    if(num==Parent[num]){
        return num;
    }
    return Parent[num]=find(Parent[num],Parent);
}



class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>> jsp;
        for(int i=0;i<deadline.size();i++){
            jsp.push_back({deadline[i],profit[i]});
        }
        sort(jsp.begin(),jsp.end(),comp);
        
        int dead=0;
        for(int i=0;i<deadline.size();i++){
            dead=max(dead,jsp[i].first);
        }
    
        vector<int>Parent(dead+1);
        for(int i=0;i<=dead;i++){
            Parent[i]=i;
        }
        
        vector<int> ans(2,0);
        
        for(int i=0;i<deadline.size();i++){
            int slot=find(jsp[i].first,Parent);
            if(slot>0){
                ans[0]++;
                ans[1]+=jsp[i].second;
                Parent[slot]=slot-1;
            }
        }
        
        return ans;
        
    }
};