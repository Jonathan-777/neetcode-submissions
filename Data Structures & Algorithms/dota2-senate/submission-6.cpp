class Solution {
public:
    string predictPartyVictory(string senate) {
        int count = 0;

        for(int i = 0; i < senate.size(); ++i){
            char elizabeth_warren  = senate[i];

            if(elizabeth_warren == 'R'){
                if(count < 0){
                    senate.push_back('D');
                }
                count++;
            }

            if(elizabeth_warren == 'D'){
                if(count > 0){
                    senate.push_back('R');
                }
                count--;
            }

        }


        return (count > 0) ? "Radiant" : "Dire";
    }
};