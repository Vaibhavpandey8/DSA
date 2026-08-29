class Solution {
  public:
    int findMin(int n) {
        // code here
        int coins=0;
        int curr[4]={10,5,2,1};
        int i=0;
        while(n){
            int digit=n/curr[i];
            while(digit--){
                coins++;
            }
            n%=curr[i];
            i++;
        }
        return coins;
    }
};