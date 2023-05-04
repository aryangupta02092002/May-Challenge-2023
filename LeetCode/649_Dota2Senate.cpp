class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq, dq;
        for(int i=0; i<senate.size(); i++){
            senate[i] == 'R' ? rq.push(i) : dq.push(i);
        }
        int x, y;
        while(!rq.empty() && !dq.empty()){
            x = rq.front();
            y = dq.front();
            rq.pop();
            dq.pop();
            
            if(x < y){
                rq.push(x + senate.size());
            }
            else{
                dq.push(y + senate.size());
            }
        }
        if(rq.size() > dq.size()){
            return "Radiant";
        }
        else{
            return "Dire";
        }
    }
};
