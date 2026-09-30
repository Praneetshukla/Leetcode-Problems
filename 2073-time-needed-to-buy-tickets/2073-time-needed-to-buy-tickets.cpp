class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        queue<pair<int,int>> Q ;

        for(int i = 0 ; i < tickets.size(); i++){
            Q.push({tickets[i],i});
        }
        while(!Q.empty()){
            pair<int,int> temp = Q.front();
            Q.pop();

            temp.first--;
            count++;

            if(temp.first==0 && temp.second == k){
                return count;
            }
          
            if(temp.first>0){
                Q.push(temp);
            }
        }
        return count;
    }
};