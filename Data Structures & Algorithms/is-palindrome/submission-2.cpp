#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        auto forward_it = s.begin();
        auto backward_it = s.rbegin();

        while(backward_it.base()-1  > forward_it){// wont check center
            if(!isalnum(static_cast<unsigned char>(*backward_it)) ){
                backward_it = next(backward_it);
                continue;
            }
            if(!isalnum(static_cast<unsigned char>(*forward_it))){
                forward_it++;
                continue;
            }


            char l = tolower(static_cast<unsigned char>(*forward_it));
            char r = tolower(static_cast<unsigned char>(*backward_it));

            if(l != r)return false;
            backward_it = next(backward_it);
            forward_it++;
        }
        return (isalnum(*forward_it)) ? tolower(*forward_it) == tolower(*backward_it) : true;
    }
};
