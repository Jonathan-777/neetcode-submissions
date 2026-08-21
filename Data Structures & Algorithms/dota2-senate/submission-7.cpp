class Solution {
public:
    string predictPartyVictory(string senate) {

        int balance = 0;

        for(int i = 0; i < senate.size(); ++i){
            const auto& Warren = senate[i];

            if(Warren == 'D'){
                if(balance < 0){
                    senate.push_back('R');
                }
                balance++;
            }else{
                if(Warren == 'R'){
                    if(balance > 0){
                        senate.push_back('D');
                    }
                    balance--;
                }
            }

        }
        return (balance > 0)? "Dire" : "Radiant";
        
    }
};