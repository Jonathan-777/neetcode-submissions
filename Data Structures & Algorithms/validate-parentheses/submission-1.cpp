class Solution {
public:
    bool isValid(string str) {
        stack<char> s;

        auto add_parentheses = [&](char c){
            switch (c){

                case '[':
                            s.push(']');
                        break;
                case '{':
                            s.push('}');
                        break;
                case '(':
                            s.push(')');
                        break;
                default:
                    if(s.empty() || c != s.top()){
                        return false;
                    }
                    if(!s.empty() &&  c == s.top())s.pop();

            }
            return true;

        };
        
        for(auto c : str){
          if( !add_parentheses(c)){
            return false;
          }
        }
        return s.empty();
    }
};
