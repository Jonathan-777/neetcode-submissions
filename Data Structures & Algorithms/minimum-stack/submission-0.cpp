class MinStack {
public:
    vector<pair<int, int>> stk;
    vector<int> min;
    MinStack(){}
    
    void push(int val) {
        if(stk.empty()){
            stk.push_back({val, val});
        } else {
            if(val > stk.back().second){
                stk.push_back({val, val});
            } else {
                stk.push_back({val, stk.back().second});
            }
        }

        if(min.empty()){
            min.push_back(val);
        } else {
            if(val < min.back()){
                min.push_back(val);
            } else{
                min.push_back(min.back());
            }
        }
        
    }
    
    void pop() {
        stk.pop_back();
        min.pop_back();
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return min.back();
    }
};
