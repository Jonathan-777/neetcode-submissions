class MyCircularQueue {
public:
    vector<int> que;
    int front_idx = 0;
    int back_idx = -1;
    MyCircularQueue(int k) : que(k,INT_MIN) {
        
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        if(back_idx + 1 < que.size()){
            back_idx++;
            que[back_idx] = value;
        }else if(back_idx == que.size() -1){
            back_idx = 0;
            que[back_idx]  = value; 
        }else{
            back_idx++;
            que[back_idx]  = value; 
        }
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        
            que[front_idx] = INT_MIN;
            front_idx++;


        
        if(front_idx >= que.size()){
            front_idx = 0;
        }
        return true;
        
    }
    
    int Front() {
        if(isEmpty())return -1;
        return que[front_idx];
        
    }
    
    int Rear() {
        if(isEmpty())return -1;
        return que[back_idx];
        
    }
    
    bool isEmpty() {// returns true if empty
        
        for(const auto & i : que){
            if( i != INT_MIN){
                return false;
            }
        }
        return true;
    }
    
    bool isFull() {// returns true when its full

        for(const auto& i : que){
            if(i == INT_MIN){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */